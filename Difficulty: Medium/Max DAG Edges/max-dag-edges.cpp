class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int e = edges.size();
        V = V*(V-1)/2;
        return V -e;
    }
};
