#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool visited[N];
int cnt=0;
int  dfs(int src)
{
    cnt ++;
    visited[src] = true;
    for (int child : v[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
    return cnt;
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
    memset(visited, false, sizeof(visited));
    int src;
    cin >> src;
    cout << dfs(src);
    return 0;
}