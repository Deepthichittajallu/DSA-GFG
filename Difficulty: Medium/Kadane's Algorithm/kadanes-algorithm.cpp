class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxi = INT_MIN;
        int maxi1 = INT_MIN;
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            maxi1 = max(sum,arr[i]);
            maxi = max(maxi,maxi1);
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};