class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string>temp;
        for(auto it:arr)
        {
            temp.push_back(to_string(it));
        }
         sort(temp.begin(),temp.end(),[](const string &a,const string &b){
            return a+b > b+a;
        });
        string res = "";
        for(auto it:temp)
        {
            res += it;
        }
        int i=0;
        while(res[i] == '0')
        {
            if(res[i] == '0') i++;
            if(i == res.size()-1) return "0";
        }
        return res;
    }
};