#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
int parentArray[N];
bool cycle;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        cout << parent << endl;
        q.pop();

        for (int child : adj[parent])
        {
            if (visited[child] && parentArray[parent] != child)
            {
                cycle = true;
            }

            if (!visited[child])
            {
                visited[child] = true;
                parentArray[child] = parent;
                q.push(child);
            }
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
            bfs(i);
        }
    }
    cycle ? cout << "Cycle Found" : cout << "Cycle Not Found";

    return 0;
}