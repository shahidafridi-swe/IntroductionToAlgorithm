// Practice Problem 3

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
  
    // for (int val : mat[2])
    // {
    //     cout << val << " ";
    // }
    int N;
    cin >> N;
    cout << mat[N].size();

    return 0;
}