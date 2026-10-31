class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD=1e9+7;
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>>R(m+1, vector<int>(n+1,0));
        vector<vector<int>>D(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
            long long total = (i == 0 && j == 0) ? 1 : (R[i][j] + D[i][j]) % MOD;
                    if (total == 0) 
                     continue;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + total) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + total) % MOD;
                } else {
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + R[i][j]) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + D[i][j]) % MOD;
                }
            }
        }
        return (R[m - 1][n - 1] + D[m - 1][n - 1]) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna