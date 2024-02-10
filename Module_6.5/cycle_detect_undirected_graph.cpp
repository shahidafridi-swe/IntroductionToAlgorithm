// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
 
    bool visited[100005];
    int parentArray[100005];
    bool cycle;
    void dfs(int parent,vector<int> adj[])
    {
        visited[parent] = true;
        
        for (int child : adj[parent])
        {
            if (visited[child] && child != parentArray[parent])
            {
                cycle = true;
            }
            if (visited[child] == false)
            {
                parentArray[child] = parent;
                dfs(child, adj);
            }
        }
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        memset(visited, false, sizeof(visited));
        memset(parentArray, -1, sizeof(parentArray));
        cycle = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i,adj);
            }
        }
        return cycle;
        
    }
};