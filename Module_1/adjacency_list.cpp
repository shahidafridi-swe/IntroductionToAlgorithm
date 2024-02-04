#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<int> mat[node];
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a); // reverse connection for undirected graph
    }
    for (int i = 0; i < mat[0].size(); i++)
    {
        cout << mat[0][i] << " ";
    }
    cout << endl;
    for (int val : mat[1])
    {
        cout << val << " ";
    }

    return 0;
}