#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector <pair<int, int >> adj[N];
int dis[N]; //distance

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src,0});
    dis[src] = 0;
    while(!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;
        for(pair<int, int> child: adj[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dis[childNode])
            {
                //path relax
                dis[childNode] = parentCost + childCost;
                q.push({childNode, dis[childNode]});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    for(int i=0; i<n ; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for(int i=0; i<n ; i++)
    {
        cout << i << "-> " << dis[i] << endl;
    }

    return 0;
}