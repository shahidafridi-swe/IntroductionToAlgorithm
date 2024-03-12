#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subset_sum(int n, int a[], int sum)
{

    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (a[n - 1] <= sum)
    {
        bool op1 = subset_sum(n - 1, a, sum - a[n - 1]);
        bool op2 = subset_sum(n - 1, a, sum);
        return dp[n][sum] = op1 || op2;
    }
    else
    {
        bool op2 = subset_sum(n - 1, a, sum);
        return dp[n][sum] = op2;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, M;
        cin >> n >> M;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum = 1000 - M;

        memset(dp, -1, sizeof(dp));
        subset_sum(n, a, sum) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}