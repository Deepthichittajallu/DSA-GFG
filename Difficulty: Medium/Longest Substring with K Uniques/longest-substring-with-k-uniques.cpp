class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int maxi = -1;
        int i=0;
        int j=0;
        int n = s.size();
        map<char,int>mp;
        while(j < n)
        {
            mp[s[j]]++;
            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size() == k)
            {
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};