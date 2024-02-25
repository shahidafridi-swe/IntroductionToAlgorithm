#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n];

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    vector<Edge> edge_list;
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> x : adj[i])
        {
            edge_list.push_back(Edge(i, x.first, x.second));
        }
    }

    for(Edge edge : edge_list)
    {
        cout << edge.u << " " << edge.v << " " << edge.w << endl;
    }

    return 0;
}