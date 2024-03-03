// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int dp[1001];
    int minCost(vector<int>& cost, int n)
    {
        if(dp[n] != -1 ) return dp[n];
        if(n<=1) return dp[n] = 0;
        if(n==2) return dp[n] = min(cost[1], cost[0]);
        return dp[n] = min(minCost(cost, n-1)+cost[n-1], minCost(cost, n-2)+cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return  minCost(cost, n);
    }
};