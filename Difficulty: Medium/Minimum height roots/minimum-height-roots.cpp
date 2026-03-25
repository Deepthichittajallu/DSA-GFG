class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear(); 
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                result.push_back(node);
                for (int nei : adj[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) q.push(nei);
                }
            }
        }
        return result;
    }
};