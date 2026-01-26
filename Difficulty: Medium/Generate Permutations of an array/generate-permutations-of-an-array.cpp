class Solution {
  public:
  vector<vector<int>>res;
  void fun(vector<int>& arr,int n,int ind)
  {
      if(ind == n-1)
      {
          res.push_back(arr);
          return ;
      }
      for(int i=ind;i<n;i++)
      {
          swap(arr[i],arr[ind]);
          fun(arr,n,ind+1);
          swap(arr[i],arr[ind]);
      }
  }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n = arr.size();
        fun(arr,n,0);
        return res;
    }
};