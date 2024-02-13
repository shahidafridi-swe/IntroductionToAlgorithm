#include <bits/stdc++.h>
using namespace std;
const long long int N = 1000;
vector<pair<long long int, long long int>> adj[N];
long long int dis[N]; // distance
class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<long long int, long long int> parent = pq.top();
        pq.pop();
        long long int parentNode = parent.first;
        long long int parentCost = parent.second;
        for (pair<long long int, long long int> child : adj[parentNode])
        {
            long long int childNode = child.first;
            long long int childCost = child.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    long long int src;
    cin >> src;
    dijkstra(src);

    int t;
    cin >> t;
    while (t--)
    {
        long long int d;
        long long int dw;
        cin >> d >> dw;
        dis[d] <= dw ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}