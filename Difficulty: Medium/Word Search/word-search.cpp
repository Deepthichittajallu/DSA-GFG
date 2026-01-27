class Solution {
  public:
  bool dfs(vector<vector<char>> &grid, string &word,int r,int c,int m,int n,vector<vector<int>>&vis,int i,string &ans)
  {
      
      if(ans == word) return true;
      
      if(r < 0 || r >= m || c < 0 || c >= n) return false;
      
      
     
      
      if(vis[r][c] == 1) return false;
      
      if(word[i] != grid[r][c]) return false;
      
      vis[r][c] = 1;
      
      ans += grid[r][c];
      i++;
      
      
      
    //   if(word[i] == grid[r][c])
    //   {
    //       ans += grid[r][c];
    //       i++;
    //   }
      
      bool btm = dfs(grid,word,r+1,c,m,n,vis,i,ans);
      bool top = dfs(grid,word,r-1,c,m,n,vis,i,ans);
      bool rht = dfs(grid,word,r,c+1,m,n,vis,i,ans);
      bool lft = dfs(grid,word,r,c-1,m,n,vis,i,ans);
      
      vis[r][c] = 0;
      ans.pop_back();
      return (btm || top || rht || lft);
      
  }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                string ans = "";
                vector<vector<int>>vis(m,vector<int>(n,0));
                if(dfs(mat,word,i,j,m,n,vis,0,ans)) return true;
            }
        }
        
        return false;
       
    }
};