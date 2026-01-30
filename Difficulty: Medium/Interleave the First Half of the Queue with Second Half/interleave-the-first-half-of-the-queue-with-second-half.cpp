class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        vector<int>v1,v2;
        int i=0;
        int n = q.size();
        while(i<n/2)
        {
            v1.push_back(q.front());
            q.pop();
            i++;
        }
        while(i<n)
        {
            v2.push_back(q.front());
            q.pop();
            i++;
        }
        int j = 0;
        queue<int>res;
        while(j < n/2)
        {
            res.push(v1[j]);
            res.push(v2[j]);
            j++;
        }
        q = res;
    }
};