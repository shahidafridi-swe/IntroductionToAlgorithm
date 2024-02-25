#include <bits/stdc++.h>
using namespace std;

void adj_list_to_matrix(int n, vector<int> adj[])
{
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (i == j) ? mat[i][j] = 1 : mat[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int child : adj[i])
        {
            mat[i][child] = 1;
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
    vector<int> adj[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj_list_to_matrix(n, adj);
    return 0;
}