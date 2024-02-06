#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005];

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;
    bool paici = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int parent = p.first;
        int parentLevel = p.second;
        if (parent == des)
        {
            cout << parentLevel << endl;
            paici = true;
        }

        for (int child : v[parent])
        {
            if (!visited[child])
            {
                q.push({child, parentLevel + 1});
                visited[child] = true;
            }
        }
    }
    if (!paici)
        cout << -1 << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        memset(visited, false, sizeof(visited));
        bfs(src, des);
    }

    return 0;
}