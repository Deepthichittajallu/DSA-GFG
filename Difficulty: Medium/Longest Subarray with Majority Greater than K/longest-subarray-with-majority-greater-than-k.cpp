class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        int sum = 0,cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] > k) sum++;
            else  sum--;
            if(sum > 0 ) cnt = i+1;
            else
            {
                if(mp.find(sum - 1) != mp.end())
                {
                    cnt = max(cnt,i-mp[sum-1]);
                }
            }
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i; 
            }
        }
        return cnt;
    }
};