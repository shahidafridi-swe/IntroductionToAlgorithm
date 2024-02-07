#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n, m;
vector<int> room;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int src_i, int src_j, int &roomCount)
{
    roomCount++;
    visited[src_i][src_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + d[i].first;
        int child_j = src_j + d[i].second;
        if (valid(child_i, child_j) && !visited[child_i][child_j] && a[child_i][child_j] == '.')
        {
            dfs(child_i, child_j, roomCount);
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

    memset(visited, false, sizeof(visited));

    int componentCount = 0;
    int roomCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] == '.')
            {
                int roomCount = 0;

                dfs(i, j, roomCount);
                room.push_back(roomCount);
                componentCount++;
            }
        }
    }
    sort(room.begin(), room.end());
    if (room.empty())
    {
        cout << 0;
    }
    else
    {

        for (int val : room)
        {
            cout << val << " ";
        }
    }
    return 0;
}