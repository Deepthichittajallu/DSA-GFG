// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<>>pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        int i=0;
        int ele = 0;
        while(i<k)
        {
            ele = pq.top();
            pq.pop();
            i++;
        }
        return ele;
    }
};