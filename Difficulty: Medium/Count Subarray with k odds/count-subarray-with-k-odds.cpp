class Solution {
  public:
 int fun(vector<int>&arr,int k)
 {
     int ans = 0;
     int j =0,o=0;
     for(int i=0;i<arr.size();i++)
     {
         if(arr[i]%2 == 1)
         {
             o++;
         }
         while( o > k)
         {
             if(arr[j] % 2 == 1) o--;
             j++;
         }
         ans += (i-j+1);
     }
     return ans;
 }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int less = fun(arr,k);
        int gtr = fun(arr,k-1);
        return less - gtr;
    }
};