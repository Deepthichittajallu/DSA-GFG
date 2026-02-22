class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<long,long>mp;
        long xo = 0;
        long res =0;
        for(long i=0;i<arr.size();i++)
        {
            xo = xo ^ arr[i];
            res = res + mp[xo^k];
            if(xo == k)
            {
                res++;
            }
            mp[xo]++;
        }
        return res;
    }
};