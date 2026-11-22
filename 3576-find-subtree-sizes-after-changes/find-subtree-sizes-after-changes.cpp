class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> st[26];

        // Find nearest ancestor with same character
        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';

            int newParent = -1;

            if (!st[ch].empty()) {
                newParent = st[ch].back();
            }

            st[ch].push_back(node);

            for (int child : adj[node]) {
                dfs(child);
            }

            st[ch].pop_back();
        };

        vector<int> newParent(n, -1);

        function<void(int)> findParent = [&](int node) {
            int ch = s[node] - 'a';

            if (!st[ch].empty()) {
                newParent[node] = st[ch].back();
            }

            st[ch].push_back(node);

            for (int child : adj[node]) {
                findParent(child);
            }

            st[ch].pop_back();
        };

        findParent(0);

        // Build modified tree
        for (int i = 1; i < n; i++) {
            if (newParent[i] != -1) {
                newAdj[newParent[i]].push_back(i);
            } else {
                newAdj[parent[i]].push_back(i);
            }
        }

        // Calculate subtree sizes
        vector<int> ans(n, 1);

        function<void(int)> dfs2 = [&](int node) {
            for (int child : newAdj[node]) {
                dfs2(child);
                ans[node] += ans[child];
            }
        };

        dfs2(0);

        return ans;
    }
};