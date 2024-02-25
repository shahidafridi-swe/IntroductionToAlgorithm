#include <bits/stdc++.h>
using namespace std;

void adj_list_to_matrix_weighted_graph(int n, vector<pair<int, int>> adj[])
{
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // (i == j) ? mat[i][j] = 0 : mat[i][j] = -1;
            mat[i][j] = (i == j) ? 0 : -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            int childNode = child.first;
            int cost = child.second;
            mat[i][childNode] = cost;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

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
    adj_list_to_matrix_weighted_graph(n, adj);
    return 0;
}