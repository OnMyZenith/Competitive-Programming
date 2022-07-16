// Binary Lifting with LCA
// Use RMQ_LCA if time limits are tight
vector<int> dep(n);
int LGMX = int(ceil(log2(n)) + 2);
vector<vector<int>> up(n, vector<int>(LGMX, -1));
y_combinator([&](auto self, int v, int p) -> void {
    if (p < 0) {
        up[v][0] = v;
        dep[v] = 0;
    } else {
        up[v][0] = p;
        dep[v] = dep[p] + 1;
    }

    for (int lvl = 1; lvl < LGMX; lvl++) {
        up[v][lvl] = up[up[v][lvl - 1]][lvl - 1];
    }

    for (auto &u : adj[v]) {
        if (u != p) self(u, v);
    }
})(0, -1);

auto getAncestor = [&](int v, int steps) -> int {
    for (int j = 0; j < LGMX; j++) {
        if (steps >> j & 1) {
            v = up[v][j];
        }
    }
    return v;
};

auto getLCA = [&](int u, int v) -> int {
    if (dep[u] > dep[v]) swap(u, v);
    v = getAncestor(v, dep[v] - dep[u]);

    int lo = -1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (getAncestor(u, mid) == getAncestor(v, mid)) hi = mid - 1;
        else
            lo = mid;
    }
    if (lo < 0) return v;
    return up[getAncestor(v, lo)][0];
};
