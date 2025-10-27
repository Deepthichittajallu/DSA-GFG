class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
          vector<vector<int>>res;
          priority_queue<
          pair<int,pair<int,int>>,
          vector<pair<int,pair<int,int>>>,
          greater<pair<int,pair<int,int>>>
          >pq;
//           priority_queue<
//     pair<int, pair<int, int>>,
//     vector<pair<int, pair<int, int>>>,
//     greater<pair<int, pair<int, int>>>
// > pq;

          for(int i=0;i<arr2.size() && i<k;i++)
          {
              pq.push({arr1[0]+arr2[i],{0,i}});
          }
          while(!pq.empty() && res.size() < k)
          {
              auto top = pq.top();
              pq.pop();
              int i = top.second.first;
              int j = top.second.second;
              res.push_back({arr1[i],arr2[j]});
              if(i+1 < arr1.size())
              {
                  pq.push({arr1[i+1]+arr2[j],{i+1,j}});
              }
          }
          return res;
    }
};