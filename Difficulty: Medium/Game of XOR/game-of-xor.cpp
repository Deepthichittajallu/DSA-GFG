class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xo = 0;
        int temp = 0 ;
        for(int i=0;i<arr.size();i++)
        {
            if((i+1)%2 != 0 && (n-i)%2!=0)
            {
                xo = (xo^arr[i]);
            }
        }
        return xo;
    }
};