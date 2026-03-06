class Solution {
  public:
  bool fun(vector<int>&frq1,vector<int>&frq2)
  {
     for(int i=0;i<26;i++)
     {
         if(frq2[i] < frq1[i]) return false;
     }
      return true;
  }
    string minWindow(string &s, string &p) {
        // code here
        vector<int>frq1(26,0);
        vector<int>frq2(26,0);
        for(auto it:p)
        {
            frq1[it - 'a']++;
        }
        int mini = INT_MAX;
        string res = "";
        int l = 0,r = 0;
        while(r < s.size())
        {
            frq2[s[r] - 'a']++;
            while(fun(frq1,frq2))
            {
                if(r-l+1 < mini)
                {
                    res = s.substr(l,r-l+1);
                    mini = r-l+1;
                }
                frq2[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return res;
    }
};