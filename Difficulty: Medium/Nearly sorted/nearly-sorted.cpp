class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:arr)
        {
            pq.push(it);
        }
        // while(!pq.empty())
        // {
        //     cout<<pq.top();
        //     pq.pop();
        // }
       int i=0;
       while(!pq.empty())
       {
           arr[i] = pq.top();
           i++;
           pq.pop();
       }
    }
};