class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        if(arr.size() == 1) return arr[0];
        int prod = 1;
        int maxi = INT_MIN;
        int res = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] != 0)
            {
                prod = prod*arr[i];
            }
            else
            {
                 prod = 1;
                continue;
            }
            maxi = max(maxi,prod);
        }
        prod = 1;
        for(int i = arr.size() -1;i>=0;i--)
        {
            if(arr[i] != 0)
            {
                prod = prod*arr[i];
            }
            else
            {
                prod = 1;
                continue;
            }
            res = max(res,prod);
        }
        return (max(maxi,res) < 0 ? 0 : max(maxi,res));
    }
};