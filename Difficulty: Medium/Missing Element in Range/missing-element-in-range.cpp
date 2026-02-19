class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        vector<int>ans;
        for(int i = low;i<=high;i++)
        {
            if(mp[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
