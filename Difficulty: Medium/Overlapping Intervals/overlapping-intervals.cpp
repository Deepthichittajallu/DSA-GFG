class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        stack<pair<int,int>>st;
        sort(arr.begin(),arr.end());
        st.push({arr[0][0],arr[0][1]});
        for(int i=1;i<arr.size();i++)
        {
            int a = 0,b = 0;
            auto it = st.top();
            int prev1 = it.first;
            int prev2 = it.second;
            int cur1 = arr[i][0];
            int cur2 = arr[i][1];
          if(prev2 >= cur1)
          {
                st.pop();
                 b = max(prev2,cur2);
                 a = min(prev1,cur1);
          }
          else
          {
                a = arr[i][0];
                b = arr[i][1];
          }
          st.push({a,b});      
          }
          vector<vector<int>>res;
          while(!st.empty())
          {
              auto it = st.top();
              int a = it.first;
              int b = it.second;
            //   cout<<a<<" "<<b<<endl;
              res.push_back({a,b});
              st.pop();
          }
            reverse(res.begin(),res.end());
          return res;
           
    }
};