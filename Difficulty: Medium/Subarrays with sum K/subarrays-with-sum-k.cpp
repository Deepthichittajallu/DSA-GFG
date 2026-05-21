class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        map<int,int>mp;
        mp[0] = 1;
        int ans = 0;
        for(int i =0;i<arr.size();i++)
        {
            sum += arr[i];
            if(mp.find(sum - k) != mp.end())
            {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};