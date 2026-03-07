class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));
        dp[0][0] = 1;
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=x;j++)
            {
                for(int k = 1;k<=m;k++){
                    if(dp[i-1][j] > 0 && j+k <= x){
                        dp[i][j+k] += dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][x];
    }
};