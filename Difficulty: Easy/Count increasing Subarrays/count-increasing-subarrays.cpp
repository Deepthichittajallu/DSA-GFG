class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int cnt = 1;
        int ans = 0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] > arr[i-1])
            {
                cnt++;
            }
            else
            {
                ans += (((cnt-1) * cnt)/2);
                cnt = 1;
            }
        }
        if(cnt != 0)
        {
            ans += (((cnt-1) * cnt)/2);
        }
        return ans;
    }
};

