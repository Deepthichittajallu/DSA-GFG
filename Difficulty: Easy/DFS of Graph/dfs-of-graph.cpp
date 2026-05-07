class Solution {
  public:
  void fun(int node,vector<vector<int>>& adj,vector<bool>&vis,vector<int>&ans)
  {
      vis[node] = true;
      ans.push_back(node);
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              fun(it,adj,vis,ans);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n = adj.size();
        vector<bool>vis(n,false);
        fun(0,adj,vis,ans);
        return ans;
    }
};