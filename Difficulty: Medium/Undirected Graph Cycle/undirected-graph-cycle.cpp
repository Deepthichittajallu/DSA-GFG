class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<int>vis(V,-2);
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<V;i++)
        {
        if(vis[i] == -2)
        {
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i] = 1;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(auto it:adj[top.first])
            {
                if(vis[it] == -2)
                {
                    vis[it] = 1;
                    q.push({it,top.first});
                }
                else if(top.second != it) return true;
            }
        }
        }
        }
        return false;
    }
};