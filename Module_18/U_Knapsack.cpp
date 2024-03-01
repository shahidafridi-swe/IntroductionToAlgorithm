#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int wt[], int val[], int W)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] <= W)
    {
        int op1 = knapsack(n - 1, wt, val, W - wt[n - 1]) + val[n - 1];
        int op2 = knapsack(n - 1, wt, val, W);
        return max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n - 1, wt, val, W);
        return op2;
    }
}

int main()
{
    int n, W;
    cin >> n >> W;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n, wt, val, W);

    return 0;
}