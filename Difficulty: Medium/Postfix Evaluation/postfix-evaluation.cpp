class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>s;
        for(int i=0;i<arr.size();i++)
        {
            if(!s.empty() && arr[i] == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(!s.empty() && arr[i] == "-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(!s.empty() && arr[i] == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(!s.empty() && arr[i] == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(floor((double)b/a));
            }
            else if(!s.empty() && arr[i] == "^")
            {
                int a =s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(b == 0) s.push(0);
                else if(a==0) s.push(1);
                else s.push(pow(b,a));
            }
            else {
                s.push(stoi(arr[i]));
            }
        }
        int res = s.top();
        return res;
    }
};