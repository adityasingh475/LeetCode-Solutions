class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n), par(n), order;
        vector<int> mask(n);
        int timer = 0;

        vector<int> st = {0};
        par[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            tin[u] = timer++;
            order.push_back(u);

            for (int v : g[u]) {
                if (v == par[u] && u != 0) continue;
                if (v == 0 && u == par[u]) continue;
                par[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int u = 0; u < n; u++) up[0][u] = par[u];

        for (int k = 1; k < LOG; k++)
            for (int u = 0; u < n; u++)
                up[k][u] = up[k - 1][up[k - 1][u]];

        vector<int> sz(n, 1);
        for (int i = n - 1; i > 0; i--) sz[par[order[i]]] += sz[order[i]];
        for (int u = 0; u < n; u++) tout[u] = tin[u] + sz[u] - 1;

        vector<int> bit(n + 2);

        auto add = [&](int i, int x) {
            for (i++; i <= n; i += i & -i) bit[i] ^= x;
        };

        auto range = [&](int l, int r, int x) {
            add(l, x);
            if (r + 1 < n) add(r + 1, x);
        };

        auto get = [&](int i) {
            int x = 0;
            for (i++; i > 0; i -= i & -i) x ^= bit[i];
            return x;
        };

        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
            range(tin[u], tout[u], mask[u]);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int d = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++)
                if (d & (1 << k)) u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return par[u];
        };

        vector<bool> ans;

        for (auto &q : queries) {
            string type;
            int u;
            string b;
            stringstream ss(q);
            ss >> type >> u >> b;

            if (type == "update") {
                int x = 1 << (b[0] - 'a');
                int delta = mask[u] ^ x;
                range(tin[u], tout[u], delta);
                mask[u] = x;
                s[u] = b[0];
            } else {
                int v = stoi(b);
                int w = lca(u, v);
                int x = get(tin[u]) ^ get(tin[v]) ^ mask[w];
                ans.push_back((x & (x - 1)) == 0);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna