#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
int parentArray[N];
bool cycle;

void dfs(int parent)
{
    visited[parent] = true;
    cout << parent << endl;
    for (int child : adj[parent])
    {
        if (visited[child] && child != parentArray[parent])
        {
            cycle = true;
        }
        if (visited[child] == false)
        {
            parentArray[child] = parent;
            dfs(child);
        }
    }
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
        adj[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(parentArray, -1, sizeof(parentArray));
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