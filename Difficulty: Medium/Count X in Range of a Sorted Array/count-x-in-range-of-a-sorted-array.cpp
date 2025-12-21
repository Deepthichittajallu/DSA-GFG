class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            int st = queries[i][0];
            int end = queries[i][1];
            int ele = queries[i][2];
            int lind = lower_bound(arr.begin()+st,arr.begin()+end+1,ele) - arr.begin();
            int uind = upper_bound(arr.begin()+st,arr.begin()+end+1,ele) - arr.begin();
            res.push_back(uind-lind);
            // cout<<lind<<" "<<uind<<endl;
        }
        return res;
    }
};