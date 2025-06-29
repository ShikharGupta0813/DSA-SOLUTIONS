class Solution{
    public:
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n + 1);

    // Build the graph
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;

            if (d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[n] == 1e9) return {-1}; // no path

    // Reconstruct path from n to 1 using parent[]
    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    // Final output: {total_weight, node1, node2, ..., n}
    vector<int> result = {dist[n]};
    result.insert(result.end(), path.begin(), path.end());
    return result;
}
};
