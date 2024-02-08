#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
bool pathVisit[N];
vector<int> adj[N];
bool cycle = false;
void dfs(int parent)
{
    visited[parent] = true;
    pathVisit[parent] = true;
    cout << parent << endl;
    for (int child : adj[parent])
    {
        if (pathVisit[child])
        {
            cycle = true;
        }

        if (!visited[child])
        {
            dfs(child);
        }
    }
    pathVisit[parent] = false;
}

int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(visited, false, sizeof(visited));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    cycle ? cout << "Cycle Found" : cout << "Cycle Not Found";

    return 0;
}