class Solution {
  public:
  bool fun(vector<int> &stalls, int k,int mid)
  {
      int cows = 1;
      int temp = stalls[0];
      for(int i=1;i<stalls.size();i++)
      {
          if(stalls[i] - temp >= mid)
          {
              cows++;
              temp = stalls[i];
          }
      }
      if(cows >= k) return true;
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int low = 0;
        int ans = 0;
        int high = stalls.back() - stalls[0];
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(fun(stalls,k,mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};