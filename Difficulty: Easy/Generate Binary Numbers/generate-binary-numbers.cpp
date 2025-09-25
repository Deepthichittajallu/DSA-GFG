class Solution {
  public:
  string fun(int n)
  {
      string res;
      while(n!=0)
      {
          if(n%2 == 0)
          {
              res+='0';
          }
          else
          {
              res+='1';
          }
          n=n/2;
      }
      reverse(res.begin(),res.end());
      return res;
  }
    vector<string> generateBinary(int n) {
        // code here
        vector<string>res;
        for(int i=0;i<=n;i++)
        {
            res.push_back(fun(i));
        }
        return res;
    }
};