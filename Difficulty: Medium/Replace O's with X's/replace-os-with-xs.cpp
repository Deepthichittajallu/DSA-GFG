class Solution {
  public:
  void fun(vector<vector<char>>&grid,int row,int col,int m,int n)
  {
      queue<pair<int,int>>q;
      q.push({row,col});
      grid[row][col] = 'D';
      vector<int>dr = {0,0,-1,1};
      vector<int>dc = {-1,1,0,0};
      while(!q.empty())
      {
          auto top = q.front();
          q.pop();
          int r = top.first;
          int c = top.second;
          for(int i=0;i<4;i++)
          {
              int one = r + dr[i];
              int sec = c +dc[i];
              if(one >= 0 && one < m && sec >= 0 && sec < n && grid[one][sec] == 'O')
                {
                    grid[one][sec] = 'D';
                    q.push({one,sec});
                    
                }
          }
          
      }
        
  }
    void fill(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(grid[i][j] == 'O')
                    {
                        fun(grid,i,j,m,n);
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                if(grid[i][j] == 'D') grid[i][j] = 'O';
            }
        }
    }
};