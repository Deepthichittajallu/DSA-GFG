class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int cnt = 0;
        double sum = 0;
        priority_queue<double>pq;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            pq.push(arr[i]);
        }
        double half = sum/2.0;
        while(!pq.empty())
        {
            while(sum > half)
            {
                double a = pq.top();
                sum -= a;
                sum+=(a/2.0);
                pq.pop();
                pq.push(a/2.0);
                cnt++;
            }
            break;
        }
        return cnt;
    }
};