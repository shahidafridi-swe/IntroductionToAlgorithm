#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const long long int N = 1005;
long long int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        long long int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < 1e18 && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long int d;
        cin >> d;
        if (!cycle)
        {
            if (dis[d] < 1e18)
            {
                cout << dis[d] << endl;
            }
            else
                cout << "Not Possible" << endl;
        }
    }

    return 0;
}