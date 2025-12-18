class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),[](const int a,const int b){
            bool temp1 = (a%2 != 0);
            bool temp2 = (b%2 != 0);
            if( temp1 && temp2) return a > b;
            if(!temp1 && !temp2) return a < b;
            return temp1;
        });
    }
};