// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int parent[1005];
    int group_size[1005];

    void dsu_initialize(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            group_size[i] = 1;
        }
    }

    int dsu_find(int node)
    {
        if (parent[node] == -1)
            return node;
        int leader = dsu_find(parent[node]);
        parent[node] = leader;
        return leader;
    }

    void dsu_union_by_size(int node1, int node2)
    {
        int leaderA = dsu_find(node1);
        int leaderB = dsu_find(node2);
        if (group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
    class Edge
    {
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
    };

    bool cmp(Edge a, Edge b)
    {
        return (a.w < b.w);
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        dsu_initialize(V);
        vector<Edge> edgeList;
        for (int u = 0; u < V; u++)
        {
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                int w = adj[u][i];
                edgeList.push_back(Edge(u, v, w));
            }
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        int totalCost = 0;
        for (Edge ed : edgeList)
        {
            int leaderU = dsu_find(ed.u);
            int leaderV = dsu_find(ed.v);
            if (leaderU == leaderV)
                continue;
            else
            {
                dsu_union_by_size(ed.u, ed.v);
                totalCost += ed.w;
            }
        }
        return totalCost;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends