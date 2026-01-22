class Solution {
  public:
  vector<int>nxt(vector<int>&arr)
  {
       int n = arr.size();
    vector<int> ans(n, n);   
    stack<int> st;            

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            ans[st.top()] = i; 
            st.pop();
        }
        st.push(i);
    }
    return ans;

    //   vector<pair<int,int>>v;
    //   stack<pair<int,int>>st;
    //   int n = arr.size();
    //   reverse(arr.begin(),arr.end());
    //   for(int i=0;i<arr.size();i++)
    //   {
    //       if(st.empty())
    //       {
    //           st.push({arr[i],arr.size()+1});
    //           v.push_back({arr[i],arr.size()+1});
    //       }
    //       if(st.top().first >= arr[i])
    //       {
    //           st.push({arr[i],n-i});
    //           v.push_back({arr[i],n-i});
    //       }
    //       while(!st.empty() && st.top().first < arr[i])
    //       {
    //           st.pop();
    //       }
          
    //   }
    //   vector<int>ans;
    //   for(auto it:v)
    //   {
    //       ans.push_back(it.second);
    //   }
    //   return ans;
  }
    int maxPeople(vector<int> &arr) {
        // code here
        vector<int>res1 = nxt(arr);
        for(int i=0;i<res1.size();i++)
        {
            res1[i] = abs(i-res1[i]);
        }
        
        reverse(arr.begin(),arr.end());
        vector<int>res2 = nxt(arr);
        for(int i=0;i<res1.size();i++)
        {
            res2[i] = abs(i-res2[i]);
        }
        reverse(res2.begin(),res2.end());
        // for(auto it:res2)
        // {
        //      cout<<it<<" ";
        // }
        vector<int>ans;
        for(int i=0;i<res1.size();i++)
        {
            ans.push_back(res1[i] + res2[i] - 1);
        }
        int res = *max_element(ans.begin(),ans.end());
        return res;
    }
};