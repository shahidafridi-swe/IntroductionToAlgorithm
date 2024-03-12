#include <bits/stdc++.h>
using namespace std;
int dp[100005];
bool fun(int n, int cur)
{
    if (n == cur)
        return true;
    if (n < cur)
        return false;
    if (dp[cur] != -1)
        return dp[cur];
    return dp[cur] = fun(n, cur + 3) or fun(n, cur * 2);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        
        fun(n, 1) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}