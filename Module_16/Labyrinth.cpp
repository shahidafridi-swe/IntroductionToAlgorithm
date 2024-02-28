#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int vis[N][N];
int dis[N][N];

pair<int, int> path[N][N];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
int si, sj, di, dj;
bool valid(int x, int y)
{
    return !vis[x][y] && (x >= 0) and (x < n) and (y >= 0) and (y < m);
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (auto mv : moves)
        {
            int ci = a + mv.first;
            int cj = b + mv.second;
            if (valid(ci, cj))
            {
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                path[ci][cj] = {mv.first, mv.second};
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            path[i][j] = {-1, -1};
            char c;
            cin >> c;
            if (c == '#')
            {
                vis[i][j] = true;
            }
            if (c == 'A')
            {
                si = i;
                sj = j;
            }
            if (c == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(dis, -1, sizeof(dis));

    bfs();

    if (!vis[di][dj])
    {
        cout << "NO";
        return 0;
    }
    cout << " YES" << endl;
    cout << dis[di][dj] << endl;
    
    vector<pair<int, int>> ans;
    pair<int, int> dest = {di, dj};
    while (dest.first != si or dest.second != sj)
    {
        ans.push_back({path[dest.first][dest.second]});
        dest.first -= ans.back().first;
        dest.second -= ans.back().second;
    }
    reverse(ans.begin(), ans.end());
   
    for (auto i : ans)
    {
        if (i.first == 1 and i.second == 0)
        {
            cout << "D";
        }
        if (i.first == -1 and i.second == 0)
        {
            cout << "U";
        }
        if (i.first == 0 and i.second == -1)
        {
            cout << "L";
        }
        if (i.first == 0 and i.second == 1)
        {
            cout << "R";
        }
    }

    return 0;
}