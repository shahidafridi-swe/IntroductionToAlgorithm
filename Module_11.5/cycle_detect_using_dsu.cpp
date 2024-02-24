// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   
    int parent[100005];
    int group_size[100005];
    void dsu_initialize(int n)
    {
        for(int i=0; i<n; i++)
        {
            parent[i] = -1;
            group_size[i] = 1;
        }
    }
    int dsu_find(int node)
    {
        if(parent[node] == -1)
        {
            return node;
        }
        int leader = dsu_find(parent[node]);
        parent[node] = leader;
        return leader;
    }
    
    void dsu_union_by_size(int node1, int node2)
    {
        int leaderA = dsu_find(node1);
        int leaderB = dsu_find(node2);
        if(group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else{
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        dsu_initialize(V);
        
        for(int a=0; a<V; a++)
        {
            for(int b: adj[a])
            {
                int leaderA = dsu_find(a);
                int leaderB = dsu_find(b);
                if(leaderA == leaderB)
                {
                    return true;
                }
                else{
                    dsu_union_by_size(a,b);
                }
            }
        }
        return false;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends