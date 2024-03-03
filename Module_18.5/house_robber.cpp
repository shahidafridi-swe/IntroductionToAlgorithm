// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int dp[105];
    int fun(vector<int>& nums,int n)
    {
        if(n<=0) return 0;
        if(dp[n] != -1) return dp[n];
        // nibo
        int op1 = fun(nums, n-2) + nums[n-1];
        // nibo na
        int op2 = fun(nums, n-1) ;
        return dp[n] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return fun(nums, n);
    }
};