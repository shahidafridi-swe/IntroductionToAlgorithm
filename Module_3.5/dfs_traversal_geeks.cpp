// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    
    bool visited[10005];
    vector<int> v;
    
    void dfs(int src,vector<int> adj[]))
    {
        v.push_back(src);
        visited[src] = true;
        for (int child : adj[src])
        {
            if (!visited[child])
            {
                dfs(child,adj[]);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        dfs(0,adj[]);
        return v;
    
        
    }
};