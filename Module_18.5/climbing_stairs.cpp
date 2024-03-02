// https://leetcode.com/problems/climbing-stairs/description/


// Top down approach
class Solution {
public:
    int dp[46];
    int fun(int n)
    {
        if(n <=2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fun(n-1)+fun(n-2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return fun(n);
    }
};

// Bottom up approach
class Solution {
public:
    
    int climbStairs(int n) {
        int dp[46];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1] +dp[i-2];
        }
        return dp[n];
    }
};

