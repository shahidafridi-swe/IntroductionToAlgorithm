// https://atcoder.jp/contests/dp/tasks/dp_a


#include <bits/stdc++.h>
using namespace std;
int height[100005];
int dp[100005];
int frog(int i)
{
    if (i == 0)
        return 0;
    int cost = INT_MAX;
    if (dp[i] != -1)
        return dp[i];
    // way 1 = ek laf chole asbo
    cost = min(cost, frog(i - 1) + abs(height[i] - height[i - 1]));
    // way 2 = dui laf chole asbo
    if (i > 1)
        cost = min(cost, frog(i - 2) + abs(height[i] - height[i - 2]));
    return dp[i] = cost;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << frog(n - 1);
    return 0;
}