class Solution {
  public:
    int countWays(int n) {
        // your code here
        vector<int>dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
