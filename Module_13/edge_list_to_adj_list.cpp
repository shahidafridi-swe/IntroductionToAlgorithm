#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> adj[n];

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "-> ";
        for (pair<int, int> x : adj[i])
        {
            cout << "{" << x.first << "," << x.second << "} ";
        }
        cout << endl;
    }

    return 0;
}