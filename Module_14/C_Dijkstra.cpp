#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
const ll N = 1e5 + 5;
vector<pii> adj[N];
ll dis[N];
ll parentList[N];
class cmp
{
public:
    bool operator()(pii a, pii b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pii parent = pq.top();
        pq.pop();
        ll parentNode = parent.first;
        ll parentCost = parent.second;
        for (pii child : adj[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                parentList[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        parentList[i] = -1;
    }
    dijkstra(1);
    if (dis[n] == 1e18)
        cout << -1;
    else
    {
        ll x = n;
        vector<ll> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parentList[x];
        }
        reverse(path.begin(), path.end());
        for (ll val : path)
            cout << val << " ";
    }
    return 0;
}