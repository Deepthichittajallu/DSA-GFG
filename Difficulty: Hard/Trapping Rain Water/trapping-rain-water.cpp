class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int n = height.size();
        vector<int>rmax(n,0);
        for(int i=n-2;i>=0;i--)
        {
            rmax[i] = max(height[i+1],rmax[i+1]);
        }
        int ans = 0;
        int lmax = height[0];
        for(int i=1;i<n-1;i++)
        {
            lmax = max(lmax,height[i-1]);
            ans += max(0,(min(lmax,rmax[i]) - height[i]));
        }
        return ans;
    }
};