#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int level[1005];
int parentArray[1005];
bool visited[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : v[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
                parentArray[child] = parent;
            }
        }
    }
}
void print_path(int des)
{
    if (parentArray[des] == -1)
    {
        cout << des << " ";
        return;
    }
    print_path(parentArray[des]);
    cout << des << " ";
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
    int src, des;
    cin >> src >> des;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parentArray, -1, sizeof(parentArray));
    bfs(src);
    print_path(des);
    return 0;
}