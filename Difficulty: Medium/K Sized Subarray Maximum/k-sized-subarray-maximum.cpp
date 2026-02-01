class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0] = arr[0];
        suf[n-1] = arr[n-1];
        for(int i=1;i<n;i++)
        {
            if(i%k == 0)
            {
                pre[i] = arr[i];
            }
            else
            {
                pre[i] = max(pre[i-1],arr[i]);
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(i%k == k-1)
            {
                suf[i] = arr[i];
            }
            else
            {
                suf[i] = max(suf[i+1],arr[i]);
            }
        }
        vector<int>res;
        for(int i=k-1;i<n;i++)
        {
            res.push_back(max(pre[i],suf[i-k+1]));
        }
        return res;
    }
};