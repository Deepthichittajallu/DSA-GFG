class Solution {
  public:
  set<string>stu;
  void fun(string &s,int st,int n)
  {
      if(st == n)
      {
          stu.insert(s);
          return;
      }
        for(int i = st;i<=n;i++)
        {
            swap(s[st],s[i]);
            fun(s,st+1,n);
            swap(s[st],s[i]);
        }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        sort(s.begin(),s.end());
        int n = s.size();
        fun(s,0,n-1);
        vector<string>res(stu.begin(),stu.end());
        return res;
    }
};
