class Solution {
  public:
  vector<string>ans;
  void fun(vector<vector<int>>& maze,int i,int j,int m,int n,string str,vector<vector<int>>&vis)
  {
      if(i >= m || i < 0 || j >= n || j < 0) 
      {
          return;
      }
      if(maze[i][j] == 0)
      {
          return;
      }
      if(vis[i][j] == 1)
      {
          return;
      }
      if(i == m-1 && j == n-1) 
      {
          ans.push_back(str);
          return;
      }
      vis[i][j] = 1;
          str += 'U';
          fun(maze,i-1,j,m,n,str,vis);
          str.pop_back();
          str += 'D';
          fun(maze,i+1,j,m,n,str,vis);
          str.pop_back();
          str += 'L';
          fun(maze,i,j-1,m,n,str,vis);
          str.pop_back();
          str += 'R';
          fun(maze,i,j+1,m,n,str,vis);
          str.pop_back();
      vis[i][j] = 0;
      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int m = maze.size();
        int n = maze[0].size();
        string str = "";
        vector<vector<int>>vis(m,vector<int>(n,0));
        int si = 0;
        int sj = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j] == 0)
                {
                    si = i;
                    sj = j;
                    break;
                }
            }
        }
        fun(maze,0,0,m,n,str,vis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};