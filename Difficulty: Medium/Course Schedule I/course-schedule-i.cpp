class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Code here
        vector<vector<int>>adj(n);
        vector<int>deg(n,0);
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            deg[pre[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<deg.size();i++)
        {
            if(deg[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                deg[it]--;
                if(deg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        for(int i=0;i<deg.size();i++)
        {
            if(deg[i] != 0) return false;
        }
        return true;
    }
};