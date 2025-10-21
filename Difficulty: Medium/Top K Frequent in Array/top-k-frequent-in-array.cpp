class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        vector<pair<int,int>>v;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(auto it:mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(v[i].second);
        }
        return res;
    }
};
