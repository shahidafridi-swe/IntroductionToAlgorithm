// https://leetcode.com/problems/find-if-path-exists-in-graph/
class Solution
{
public:
    vector<int> v[200005];
    bool vis[200005];

    void dfs(int src)
    {
        vis[src] = true;
        for (int child : v[src])
        {
            if (!vis[child])
            {
                dfs(child);
            }
        }
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        memset(vis, false, sizeof(vis));
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(source);
        return vis[destination];
    }
};