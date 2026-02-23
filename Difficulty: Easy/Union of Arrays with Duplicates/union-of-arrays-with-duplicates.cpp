class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int>st;
        for(auto it:a)
        {
            st.insert(it);
        }
        for(auto it:b)
        {
            st.insert(it);
        }
        vector<int>res(st.begin(),st.end());
        return res;
    }
};