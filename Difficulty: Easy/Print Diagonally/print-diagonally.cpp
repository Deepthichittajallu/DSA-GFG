class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        vector<int>res;
        int i = 0,j= 0,cnt = 0;
        while(cnt < n)
        {
            i=0;
            j = cnt;
            while(j>=0)
            {
                res.push_back(mat[i++][j--]);
            }
            j++;
        cnt++;
        }
        cnt = 1;
        i = 0;
        j = 0;
        while(cnt < n)
        {
            j = n - 1;
            i = cnt;
            while( j >= cnt)
            {
                res.push_back(mat[i++][j--]);
            }
            cnt++;
        }
        return res;
    }
};