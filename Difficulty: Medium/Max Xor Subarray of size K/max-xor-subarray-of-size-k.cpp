class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int xo = 0;
        int ans = INT_MIN;
        for(int i=0;i<k;i++)
        {
            xo = (xo^arr[i]);
        }
        ans = max(ans,xo);
        int n = arr.size();
        for(int i=k;i<n;i++)
        {
            
            xo = (xo^arr[i-k]);
            xo = (xo^arr[i]);
            ans = max(ans,xo);
        }
        return ans;
    }
};