#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;
    int dp[n + 1][sum + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] <= j)
            {
                // bool op1 = dp[i - 1][j - a[i - 1]];
                // bool op2 = dp[i - 1][j];
                // dp[i][j] = op1 || op2;
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else
            {
                // bool op2 = dp[i - 1][j];
                // dp[i][j] = op2;
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][sum];

    return 0;
}