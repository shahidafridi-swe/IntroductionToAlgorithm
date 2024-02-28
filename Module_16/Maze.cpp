#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int dis[1005][1005];
char a[1005][1005];
int n, m;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pair<int, int> path[1005][1005];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int x = par.first, y = par.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[x][y] + 1;
                path[ci][cj] = {d[i].first, d[i].second};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            path[i][j] = {-1, -1};
            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    vector<pair<int, int>> ans;
    pair<int, int> dest = {di, dj};
    while (dest.first != si or dest.second != sj)
    {
        if (a[dest.first][dest.second] != 'D')
        {
            a[dest.first][dest.second] = 'X';
        }
        ans.push_back({path[dest.first][dest.second]});

        dest.first -= ans.back().first;
        dest.second -= ans.back().second;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}


