class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j] == 2) q.push({i,j});
            }
        }
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        int ans= 0;
        while(!q.empty())
        {
            bool  flag = false;
            int si = q.size();
            for(int i=0;i<si;i++)
            {
                auto top = q.front();
                q.pop();
                for(int r = 0;r<4;r++)
                {
                    int row = dr[r]+top.first;
                    int col = dc[r]+top.second;
                    if(row >= 0 && row < mat.size() && col  >= 0 && col < mat[0].size())
                    {
                        if(mat[row][col] == 1)
                        {
                            mat[row][col] = 2;
                            q.push({row,col});
                            flag = true;
                        }
                    }
                }
            }
            if(flag == true) ans++;
        }
            for(int i=0;i<mat.size();i++)
            {
                for(int j=0;j<mat[0].size();j++)
                {
                    if(mat[i][j] == 1) return -1;
                }
            }
            return ans;
    }
};