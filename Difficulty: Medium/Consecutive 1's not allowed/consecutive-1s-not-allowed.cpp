class Solution {
  public:
    int countStrings(int n) {
        // code here
        if (n == 1)
        return 2;
        if (n == 2)
            return 3;
    
        vector<int> dp(n);
        dp[n - 1] = 2;
        dp[n - 2] = 3;
    
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
    
        return dp[0];
    }
};