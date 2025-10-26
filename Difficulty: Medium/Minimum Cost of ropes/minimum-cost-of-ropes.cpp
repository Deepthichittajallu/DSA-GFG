class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        int sum = 0;
        // while(!pq.empty())
        // {
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        if(arr.size() == 1) return 0;
        // if(arr.size() == 2) return arr[0] + arr[1];
        while(!pq.empty())
        {
            if(pq.size() == 1)
            {
                // sum += pq.top();
                break;
            }
            else
            {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a+b);
            sum +=(a+b);
            }
        }
        return sum;
    }
};