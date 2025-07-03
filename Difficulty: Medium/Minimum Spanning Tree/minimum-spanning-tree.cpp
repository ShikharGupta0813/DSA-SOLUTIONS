class Solution {
  public:
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<pair<int, int>>> lis(V);
        vector<bool> vis(V, false);
        int ans = 0;

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int child = it[0];
                int wt = it[1];
                lis[i].push_back({child, wt});
            }
        }

        pq.push({0, {0, -1}});  
     
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();

            if (!vis[node]) {
                ans += wt;
                vis[node] = true;

                for (auto it : lis[node]) {
                    int nod = it.first;
                    int cost = it.second;
                    pq.push({cost, {nod, node}});
                }
            }
        }

        return ans;
    }
};
