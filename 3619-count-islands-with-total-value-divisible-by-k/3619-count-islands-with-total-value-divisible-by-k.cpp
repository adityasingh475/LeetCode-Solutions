class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        int d[5] = {-1, 0, 1, 0, -1};

        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            long long sum = grid[i][j];
            grid[i][j] = 0;

            for (int x = 0; x < 4; x++) {
                int r = i + d[x], c = j + d[x + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c])
                    sum += dfs(r, c);
            }
            return sum;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] && dfs(i, j) % k == 0)
                    ans++;

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna