class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        vector<int> pal(num);
        for (int i = 0; i < n/2; i++) {
            pal[n-1-i] = pal[i];
        }
        if (pal > num) return pal;
        int carry = 1;
        int mid = (n-1)/2;
        while (mid >= 0 && carry) {
            int val = pal[mid] + carry;
            pal[mid] = val % 10;
            carry = val / 10;
            pal[n-1-mid] = pal[mid]; 
            mid--;
        }
        if (carry) {
            pal.assign(n+1, 0);
            pal[0] = pal[n] = 1;
        }
        return pal;
    }
};