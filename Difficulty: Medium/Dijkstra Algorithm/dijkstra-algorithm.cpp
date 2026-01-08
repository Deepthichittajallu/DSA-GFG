class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX);

    // Distance from source to itself is 0
    dist[src] = 0;
    pq.emplace(0, src);

    // Process the queue until all reachable vertices are finalized
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;  
        int u = top.second; 

        // If this distance not the latest shortest one, skip it
        if (d > dist[u])
            continue;

        // Explore all neighbors of the current vertex
        for (auto &p : adj[u]) {
            int v = p.first; 
            int w = p.second; 

            // If we found a shorter path to v through u, update it
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;   
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
        // vector<int>res(V,INT_MAX);
        // // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        // queue<pair<int,int>>q;
        // q.push({0,src});
        // res[src] = 0;
        // int cost  = 0;
        // while(!q.empty())
        // {
        //     auto top = q.front();
        //     q.pop();
        //     int cost = top.first;
        //   //  cout << top.second << "--";
        //     for(auto it : adj[top.second])
        //     {
        //      //   cout << it.first << " " << it.second << endl;
                
        //         if(cost + it.second < res[it.first])
        //         {
        //             res[it.first] = cost + it.second;
        //             q.push({cost + it.second,it.first});
        //         }
        //     }
        // }
        // return res;
    }
};