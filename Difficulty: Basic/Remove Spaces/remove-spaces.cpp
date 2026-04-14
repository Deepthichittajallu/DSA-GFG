class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string res = "";
        for(auto it:s)
        {
           if(it != ' ') res += it; 
        }
        return res;
    }
};