#include <bits/stdc++.h>
using namespace std;
char a[105][105];
bool visited[105][105];
int dis[105][105];
vector<pair<int, int>> d = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
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
        for (int i = 0; i < 8; i++)
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = '.';
            }
        }
        int src_i, src_j, des_i, des_j;
        cin >> src_i >> src_j;
        cin >> des_i >> des_j;

        memset(visited, false, sizeof(visited));
        memset(dis, -1, sizeof(dis));

        bfs(src_i, src_j);
        cout << dis[des_i][des_j] << endl;
    }

    return 0;
}