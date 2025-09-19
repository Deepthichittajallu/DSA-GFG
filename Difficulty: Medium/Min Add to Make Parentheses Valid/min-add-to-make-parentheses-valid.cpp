class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char>st;
        int cnt = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(') st.push(s[i]);
            else if(!st.empty() && (st.top() =='(' && s[i] == ')'))
            {
                st.pop();
                continue;
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        return st.size();
       
    }
};