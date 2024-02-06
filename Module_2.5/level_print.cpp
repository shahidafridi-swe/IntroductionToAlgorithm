// Practice Problem 2

#include <bits/stdc++.h> 
using namespace std;
vector<int> v[1005];
int level[1005];
bool visited[1005];
vector<int> levelElement;
void bfs(int src, int l)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
     
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        if(level[parent] == l)
            levelElement.push_back(parent);
        for (int child : v[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
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
    int l;
    cin >> l;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    bfs(0, l);
    reverse(levelElement.begin(), levelElement.end());
    for(int val : levelElement)
    {
        cout << val << " ";
    }

    return 0;
}