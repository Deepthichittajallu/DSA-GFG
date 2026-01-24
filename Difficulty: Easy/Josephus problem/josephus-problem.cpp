class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        int ans = 0;
        int i = 1;
        while(i <= n)
        {
            ans = (ans + k) % i;
            i++;
        }
        return ans + 1;
    }
};