#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool visited[N];

void dfs(int src, int & nodeCount )
{
    nodeCount++;
    // cout << src << " "<< nodeCount <<   endl;
    visited[src] = true;
    for (int child : v[src])
    {
        if (!visited[child])
        {
            dfs(child,nodeCount);
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
    int nodeCount =0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i,nodeCount);
            componentCount++;
        }
    }
    if (n!= nodeCount)
    {
        int x = n-nodeCount;
        componentCount += x;
    }
    cout <<  componentCount << endl;
    return 0;
}