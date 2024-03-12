#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n, greater<ll>());
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            if (b[0] == a[i])
                v.push_back(i);
            if (b[1] == a[i])
                v.push_back(i);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}