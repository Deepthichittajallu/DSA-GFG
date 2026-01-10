class Solution {
  public:
  int fun(string &s,int k)
  {
      if(k <= 0) return 0;
      int ans = 0;
      int d = 0;
      vector<int>v(26,0);
      int j = 0;
      for(int i=0;i<s.size();i++)
      {
          if(v[s[i]-'a']==0)
          {
              d++;
          }
          v[s[i] - 'a']++;
          while(d > k)
          {
              v[s[j]- 'a']--;
              if(v[s[j]- 'a'] == 0) d--;
              j++;
          }
          ans += (i-j+1);
      }
      return ans;
  }
    int countSubstr(string& s, int k) {
        // code here
        if(k <= 0) return 0;
        int n = s.size();
        int gtr = fun(s,k);
        int gtreql = fun(s,k-1);
        return gtr - gtreql;
    }
};