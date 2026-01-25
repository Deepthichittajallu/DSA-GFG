class Solution {
  public:
  set<string>st;
  void fun(int open,int close,string s)
  {
      if(open == 0 && close == 0)
      {
          st.insert(s);
          return;
      }
      if(open > 0) fun(open-1,close,s+'(');
      if(close > open) fun(open,close-1,s+')');
  }
    int findWays(int n) {
        // code here
        if(n%2) return 0;
        int N = n/2;
        string s = "(";
        fun(N-1,N,s);
        return st.size();
    }
};