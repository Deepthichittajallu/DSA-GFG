class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int res = arr.size() + k;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] - (mid + 1) >= k)
            {
                res = mid + k;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};