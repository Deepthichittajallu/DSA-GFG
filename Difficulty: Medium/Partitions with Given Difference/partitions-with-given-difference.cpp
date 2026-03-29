class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if ((sum + diff) % 2 != 0 || sum < diff)
        return 0;

        int target = (sum + diff) / 2;
        int n = arr.size();
    
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
    
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= target; j++){
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1])
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    
        return dp[n][target];
    }
};