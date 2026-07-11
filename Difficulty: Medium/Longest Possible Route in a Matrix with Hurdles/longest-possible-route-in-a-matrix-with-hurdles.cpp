class Solution {
  public:
  int func(vector<vector<int>>& mat,int i,int j,int r,int c,vector<vector<bool>>& vis,
  int m, int n,int cnt)
  {
      if(i <0 || i >= m || j < 0 || j >= n) return -1;
      if(vis[i][j] == true) return -1;
      if(mat[i][j] == 0) return -1;
      if(i == r && j == c) return cnt;
      vis[i][j] = true;
      int top = func(mat,i-1,j,r,c,vis,m,n,cnt+1);
      int btm = func(mat,i+1,j,r,c,vis,m,n,cnt+1);
      int left = func(mat,i,j-1,r,c,vis,m,n,cnt+1);
      int right = func(mat,i,j+1,r,c,vis,m,n,cnt+1);
      vis[i][j] = false;
      return max({top,btm,left,right});
      
  }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        if(xs == xd && ys == yd) return 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt = 0;
        return func(mat,xs,ys,xd,yd,vis,m,n,cnt);
    }
};