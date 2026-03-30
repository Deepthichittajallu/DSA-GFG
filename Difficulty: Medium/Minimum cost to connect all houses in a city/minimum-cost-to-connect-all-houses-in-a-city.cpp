class Solution {
  public:
   int manhattanDistance(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
    
        // Min-heap to store {cost, house_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                                     greater<>> minHeap;
    
        // Marks whether a house is already connected
        vector<bool> visited(n, false);
    
        // Start with the first house (index 0)
        minHeap.push({0, 0});
    
        int totalCost = 0;
    
        while (!minHeap.empty()) {
            pair<int, int> p = minHeap.top(); minHeap.pop();
            int cost = p.first;
            int u = p.second;
    
            if (visited[u]) continue;
    
            // Mark the house as connected and add the cost
            visited[u] = true;
            totalCost += cost;
    
            // Calculate distance to all unvisited houses and add to heap
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = manhattanDistance(houses[u], houses[v]);
                    minHeap.push({dist, v});
                }
            }
        }
    
        return totalCost;
    }
};