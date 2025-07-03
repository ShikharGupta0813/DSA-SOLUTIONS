class DisjointSET {
    vector<int> rank, size, parent;

public:
    DisjointSET(int v) {
        rank.resize(v + 1, 0);
        size.resize(v + 1, 1);
        parent.resize(v + 1);
        for (int i = 0; i <= v; i++) parent[i] = i;
    }

    int ultimateP(int node) {
        if (node == parent[node]) return node;
        return parent[node] = ultimateP(parent[node]);
    }

    void byunion(int a, int b) {
        int Ua = ultimateP(a);
        int Ub = ultimateP(b);
        if (Ua == Ub) return;
        if (rank[Ua] > rank[Ub]) parent[Ub] = Ua;
        else if (rank[Ua] < rank[Ub]) parent[Ua] = Ub;
        else {
            parent[Ua] = Ub;
            rank[Ub]++;
        }
    }

    void bysize(int a, int b) {
        int Ua = ultimateP(a);
        int Ub = ultimateP(b);
        if (Ua == Ub) return;
        if (size[Ua] > size[Ub]) {
            parent[Ub] = Ua;
            size[Ua] += size[Ub];
        } else {
            parent[Ua] = Ub;
            size[Ub] += size[Ua];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSET ds(n);
        int cntExtras = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.ultimateP(u) == ds.ultimateP(v)) {
                cntExtras++;
            }
            else {
                ds.bysize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};