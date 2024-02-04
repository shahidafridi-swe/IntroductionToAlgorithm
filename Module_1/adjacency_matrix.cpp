#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    int mat[node][edge];
    memset(mat, 0, sizeof(mat));
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1; // reverse connection for undirected graph
    }
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    if (mat[0][1] == 1)
        cout << "connection ache" << endl;
    else
        cout << "connection nai" << endl;

    return 0;
}