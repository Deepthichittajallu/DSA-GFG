class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int l = 0;
        int r = 0;
        int n = arr.size();
        int ans = 0,cnt = 0;
        while(r < arr.size())
        {
            if(arr[r] == 1)
            {
                cnt++;
            }
            else if(arr[r] == 0)
            {
                if(k>=0) cnt++;
                k--;
                while(k<0)
                {
                    if(arr[l] == 0)
                    {
                        k++;
                        cnt--;
                    }
                    l++;
                }
            }
            r++;
            ans = max(ans,r-l);
        }
        return ans;
    }
};
