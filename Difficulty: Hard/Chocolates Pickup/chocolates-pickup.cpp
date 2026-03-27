class Solution {
  public:
  int dp[71][71][71];
  int solve(int row,int col1,int col2,vector<vector<int>>& grid,int m,int n)
  {
      if(row < 0 || col1 >= m || col2 >= m || col1 < 0 ||col2 < 0) return INT_MIN;
      if(row == n) return 0;
      if(dp[row][col1][col2] != -1) 
      {
          return dp[row][col1][col2];
      }
      int ans = 0;
      for(int i=-1;i<=1;i++)
      {
          for(int j=-1;j<=1;j++)
          {
              int val = 0;
              if(col1 == col2)
              {
                  val += grid[row][col1];
              }
              else 
              {
                  val += grid[row][col1] + grid[row][col2];
              }
              val += solve(row + 1,col1+i,col2 + j,grid,m,n);
              ans = max(ans,val);
          }
      }
      return dp[row][col1][col2] = ans;
  }
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int n,m;
        n = grid.size();
        m = grid[0].size();
        memset(dp , -1, sizeof dp);
        return solve(0,0,m-1,grid,m,n);
    }
};