class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if(y == 1) return true;
        if(x == 1) return y == 1;
        double res = log(y) / log(x);
        return fabs(res - round(res)) < 1e-10;
    }
};