class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        if(n == 1)
        {
            return  {"0","1"};
        }
        vector<string>v1 = graycode(n-1);
        vector<string>ans;
        for(int i=0;i<v1.size();i++)
        {
            string temp = '0' + v1[i];
            ans.push_back(temp);
        }
        for(int i=v1.size()-1;i>=0;i--)
        {
            string temp = '1' + v1[i];
            ans.push_back(temp);
        }
        return ans;
    }
};