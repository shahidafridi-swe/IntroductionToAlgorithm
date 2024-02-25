#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<pair<int, int>> edge_list;
    for (int i = 0; i < n; i++)
    {
        for (int x : adj[i])
        {
            edge_list.push_back({i,x});
        }
    }

    for(pair<int, int> edge : edge_list)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}