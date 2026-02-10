class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int ans = 0;
        int high = *max_element(arr.begin(),arr.end());
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int cnt = 0;
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]%mid == 0) cnt += (arr[i]/mid);
                else cnt += ((arr[i]/mid) + 1);
            }
            if(cnt <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};