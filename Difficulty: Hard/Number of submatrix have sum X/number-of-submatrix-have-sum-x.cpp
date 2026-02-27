class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=0;j<m;j++)
            {
                sum += mat[i][j];
                temp[i][j] = sum;
            }
        }
        for(int i=0;i<m;i++)
        {
            int sum = 0;
            for(int j=0;j<n;j++)
            {
                sum += temp[j][i];
                temp[j][i] = sum;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j] == x) ans++;
                }
            }
        int cnt = 1;
        int mini = min(n,m);
        while(cnt < mini)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    int tempo = INT_MIN;
                  if(i+cnt < n && j+cnt < m)
                  {
                      tempo = temp[i+cnt][j+cnt];
                      if(i-1 >= 0 && j+cnt < m)
                      {
                          tempo -= temp[i-1][j+cnt];
                      }
                      if(j-1 >= 0 && i+cnt <n)
                      {
                          tempo -= temp[i+cnt][j-1];
                      }
                      if(i-1 >=0 && j-1>=0)
                      {
                          tempo += temp[i-1][j-1];
                      }
                  }
                  if(tempo == x) ans++;
                }
            }
            cnt++;
        }
        return ans;
    }
};