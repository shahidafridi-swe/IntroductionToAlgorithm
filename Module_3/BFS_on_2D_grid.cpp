#include <bits/stdc++.h>
using namespace std;
char a[20][20];
bool visited[20][20];
int dis[20][20]; // distence/ shortest path
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int src_i, int src_j)
{
    queue<pair<int, int>> q;
    q.push({src_i, src_j});
    visited[src_i][src_j] = true;
    dis[src_i][src_j] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int parent_i = parent.first, parent_j = parent.second;
        for (int i = 0; i < 4; i++)
        {
            int child_i = parent_i + d[i].first;
            int child_j = parent_j + d[i].second;
            if (valid(child_i, child_j) && !visited[child_i][child_j])
            {
                q.push({child_i, child_j});
                visited[child_i][child_j] = true;
                dis[child_i][child_j] = dis[parent_i][parent_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int src_i, src_j;
    cin >> src_i >> src_j;
    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));

    bfs(src_i, src_j);
    cout << dis[2][3];

    return 0;
}