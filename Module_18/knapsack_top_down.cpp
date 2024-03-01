#include <bits/stdc++.h>
using namespace std;
int const N = 1000;
int wt[N], val[N];
int dp[N][N];

int knapsack(int n, int W)
{
    if (n == -1 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n-1] <= W)
    {
        int op1 = knapsack(n - 1, W - wt[n-1]) + val[n-1];
        int op2 = knapsack(n - 1, W);
        return dp[n][W] = max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n - 1, W);
        return dp[n][W] = op2;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int W;
    cin >> W;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, W);
    return 0;
}