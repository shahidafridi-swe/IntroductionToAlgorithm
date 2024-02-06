#include <bits/stdc++.h>
using namespace std;
char a[20][20];
bool visited[20][20];
vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int src_i, int src_j)
{
    cout << src_i << " " << src_j << endl;
    visited[src_i][src_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + d[i].first;
        int child_j = src_j + d[i].second;
        if (valid(child_i, child_j) && !visited[child_i][child_j] && a[child_i][child_j] == '.')
        {
            dfs(child_i, child_j);
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
    dfs(src_i, src_j);
    return 0;
}