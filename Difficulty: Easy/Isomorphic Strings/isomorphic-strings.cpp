class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        map<char,char>mp;
        vector<int>vis(26,0);
        for(int i=0;i<s1.size();i++)
        {
            if(mp.find(s1[i]) == mp.end() && vis[s2[i]-'a'] == 0)
            {
                mp[s1[i]] = s2[i];
                vis[s2[i] - 'a']++;
            }
            else if(mp[s1[i]] != s2[i]) return false;
        }
        return true;
        
    }
};