class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>nxtSmall(n,n);
        vector<int>prevSmall(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if(!s.empty())nxtSmall[i] = s.top();
            s.push(i);
        }
        stack<int>s2;
        for(int i = 0 ; i < n ; i++) {
            while(!s2.empty() && arr[s2.top()] > arr[i]) s2.pop();
            
            if(!s2.empty()) prevSmall[i] = s2.top();
            s2.push(i);
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int a = nxtSmall[i] - i;
            int b = i - prevSmall[i];
            cnt += a*b*arr[i];
        }
        return cnt;
    }
};