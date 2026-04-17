class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        map<char,int>mp;
        int cnt = 0;
        for(auto it:s)
        {
            mp[it]++;
        }
        if(s.size()%2 == 0)
        {
            for(auto it:mp)
            {
                if(it.second%2!=0) return false;
            }
        }
        else
        {
            for(auto it:mp)
            {
                if(it.second%2==1)cnt++;
                if(it.second %2 == 1 && cnt > 1) return false; 
            }
        }
        return true;
    }
};