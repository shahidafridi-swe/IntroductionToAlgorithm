#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005; // Adjust the size as needed
const int INF = 30000; // Use INT_MAX for initialization

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int dis[MAX_N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 0; i < MAX_N; i++)
    {
        dis[i] = INF;
    }
    dis[0] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] != INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}
