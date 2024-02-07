#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool visited[N];

void dfs(int src, int &nodeCount)
{
    nodeCount ++;
    visited[src] = true;
    for (int child : v[src])
    {
        if (!visited[child])
        {
            dfs(child, nodeCount);
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
    memset(visited, false, sizeof(visited));
    int componentCount = 0;
    int nodeCount= 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {   nodeCount=0;
            dfs(i,nodeCount);
            v.push_back(nodeCount);
            componentCount++;
        }
    }
    for(int val: v)
        cout << val << " " ;
    return 0;
}