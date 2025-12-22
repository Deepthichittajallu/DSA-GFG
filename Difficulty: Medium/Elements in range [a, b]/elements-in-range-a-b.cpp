class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
       sort(arr.begin(),arr.end());
       vector<int>res;
       for(int i=0;i<queries.size();i++)
       {
           int a = queries[i][0];
           int b = queries[i][1];
           int ind1 = lower_bound(arr.begin(),arr.end(),a) - arr.begin();
           int ind2 = upper_bound(arr.begin(),arr.end(),b) - arr.begin();
           res.push_back(ind2-ind1);
       }
       return res;
    }
};