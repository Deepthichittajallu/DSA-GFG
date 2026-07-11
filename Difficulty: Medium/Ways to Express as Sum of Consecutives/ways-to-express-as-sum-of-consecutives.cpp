class Solution {
  public:
    int getCount(int n) {
        // code here
        int l = 1;
        int r = 1;
        int sum = 0, ans = 0;
        while(r < n)
        {
            sum += r;
            if(sum == n) ans++;
            while(sum > n)
            {
                sum -= l;
                if(sum == n) ans++;
                l++;
            }
            r++;
            
        }
        return ans;
    }
};