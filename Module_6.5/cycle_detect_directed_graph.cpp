// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    bool visited[100005];
    bool pathVisit[100005];
   
    bool cycle = false;
    void dfs(int parent,vector<int> adj[])
    {
        visited[parent] = true;
        pathVisit[parent] = true;
        
        for (int child : adj[parent])
        {
            if (pathVisit[child])
            {
                cycle = true;
            }
    
            if (!visited[child])
            {
                dfs(child,adj);
            }
        }
        pathVisit[parent] = false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        memset(visited, false, sizeof(visited));
        memset(pathVisit, false, sizeof(pathVisit));
        cycle = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj);
            }
        }
        return cycle;
    }
};