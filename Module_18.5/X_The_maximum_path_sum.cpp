#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
ll A[15][15];
ll dp[15][15];

ll max_path_sum(int i, int j)
{
    if (i == n && j == m)
        return A[i][j];
    if (dp[i][j] != INT_MIN)
        return dp[i][j];
    ll op1 = (i < n) ? max_path_sum(i + 1, j)  : INT_MIN;
    ll op2 = (j < m) ? max_path_sum(i, j + 1) : INT_MIN;

    return dp[i][j] = max(op1, op2) + A[i][j];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
            dp[i][j] = INT_MIN;
        }
    }
    cout << max_path_sum(1, 1);
    return 0;
}