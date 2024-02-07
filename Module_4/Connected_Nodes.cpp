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
        mat[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;

        if (mat[x].empty())
        {
            cout << -1;
        }
        else
        {
            sort(mat[x].begin(), mat[x].end(), greater<int>());
            for (int val : mat[x])
            {
                cout << val << " ";
            }
        }
        cout << endl;
    }

       return 0;
}