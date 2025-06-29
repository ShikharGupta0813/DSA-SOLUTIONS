class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});  // {to, price}
        }

        queue<tuple<int, int, int>> q;  // {node, cost, stops}
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        q.push({src, 0, 0});

        while (!q.empty()) {
            auto [node, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto [neigh, price] : adj[node]) {
                if (cost + price < dist[neigh]) {
                    dist[neigh] = cost + price;
                    q.push({neigh, cost + price, stops + 1});
                } else if (stops < k) {
                    // Still push if cost is not better, but we may get better later
                    q.push({neigh, cost + price, stops + 1});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
