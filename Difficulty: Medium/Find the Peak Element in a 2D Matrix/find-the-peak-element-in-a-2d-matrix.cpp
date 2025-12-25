class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        vector<int>res;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a = INT_MIN,b= INT_MIN,c=INT_MIN,d = INT_MIN;
                if(i-1>=0) a = mat[i-1][j];
                if(i+1 < m) b = mat[i+1][j];
                if(j-1>=0) c = mat[i][j-1];
                if(j+1 < n) d = mat[i][j+1];
                if(mat[i][j] >= a && mat[i][j] >= b && mat[i][j] >= c && mat[i][j] >= d){
                    return {i,j};
                }
            }
        }
        return {INT_MIN,INT_MIN};
    }
};
