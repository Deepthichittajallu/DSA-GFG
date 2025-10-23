class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        sort(points.begin(),points.end(),[](vector<int>a,vector<int>b)
        {
            return (double)sqrt((a[0]*a[0]) + a[1]*a[1]) < (double)sqrt((b[0]*b[0]) + b[1]*b[1]);
        });
        return {points.begin(),points.begin()+k};
    }
};