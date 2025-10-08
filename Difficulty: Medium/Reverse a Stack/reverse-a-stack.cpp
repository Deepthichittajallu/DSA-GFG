class Solution {
  public:
  void insert(stack<int>&st,int val)
  {
      if(st.empty()) 
      {
          st.push(val);
          return ;
      }
      int tval = st.top();
      st.pop();
      insert(st,val);
      st.push(tval);
      
  }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int topv = st.top();
        st.pop();
        reverseStack(st);
        insert(st,topv);
    }
};