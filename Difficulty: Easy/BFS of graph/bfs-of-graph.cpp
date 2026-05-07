class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
       queue<int>q;
       int n = adj.size();
       vector<bool>vis(n,false);
       q.push(0);
       vector<int>res;
       while(!q.empty())
       {
           auto top = q.front();
           q.pop();
           res.push_back(top);
           vis[top] = true;
           for(auto it: adj[top])
           {
               if(!vis[it])
               {
                   q.push(it);
                   vis[it] = true;
               }
           }
       }
       return res;
    }
};