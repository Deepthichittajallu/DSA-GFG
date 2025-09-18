class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        vector<int>v;
        int n =  arr.size();
        for(int i=0;i<2*n;i++)
        {
            v.push_back(arr[i%n]);
        }
        stack<int>st;
        vector<int>r1;
        for(int i=v.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= v[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                r1.push_back(st.top());
                // st.push(v[i]);
            }
            else
            {
                r1.push_back(-1);
            }
            st.push(v[i]);
        }
        vector<int>res;
        reverse(r1.begin(),r1.end());
        for(int i=0;i<n;i++)
        {
            res.push_back(r1[i]);
        }
        return res;
    }
};