// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int maxi = INT_MIN;
        int ans = 0;
        int ind = 0;
        for(int i=0;i<arr.size();i++)
        {
            int n = arr[i].size();
            int lind = lower_bound(arr[i].begin(),arr[i].end(),1) - arr[i].begin();
            ans = n - lind;
            if(maxi < ans)
            {
                maxi = max(ans,maxi);
                ind = i;
            }
        }
        return ind;
    }
};