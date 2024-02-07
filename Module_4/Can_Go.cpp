#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
bool dfs(int src_i, int src_j, int des_i, int des_j)
{
    if (src_i == des_i && src_j == des_j)
    {
        return true;
    }
    visited[src_i][src_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + d[i].first;
        int child_j = src_j + d[i].second;
        if (valid(child_i, child_j) && !visited[child_i][child_j] && a[child_i][child_j] != '#')
        {
            if (dfs(child_i, child_j, des_i, des_j))
                return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    int src_i, src_j, des_i, des_j;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                src_i = i, src_j = j;
            else if (a[i][j] == 'B')
                des_i = i, des_j = j;
        }
    }

    memset(visited, false, sizeof(visited));
    (dfs(src_i, src_j, des_i, des_j)) ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}