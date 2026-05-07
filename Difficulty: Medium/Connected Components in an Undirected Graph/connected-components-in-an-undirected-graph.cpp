class Solution {
  public:
 vector<int> bfs(vector<bool>&vis,vector<vector<int>>& edges,int node)
{
    vis[node] = true;
    queue<int>pq;
    pq.push(node);
    vector<int>res;
    while(!pq.empty())
    {
        auto top = pq.front();
        pq.pop();
        res.push_back(top);
        for(auto it:edges[top])
        {
            if(!vis[it])
            {
                vis[it] = true;
                // bfs(vis,edges,it);
                pq.push(it);
            }
        }
    }
    // for(auto it:res)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    return res;
}
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        int n = V;
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // int n = adj.size();
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(auto it:adj[i])
        //     {
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>>res;
        vector<bool>vis(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                res.push_back(bfs(vis,adj,i));
                // bfs(vis,adj,i);
            }
        }
        return res;
    }
};
