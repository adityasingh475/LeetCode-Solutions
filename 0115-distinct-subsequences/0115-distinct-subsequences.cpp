class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        vector<long long> dp(m + 1);
        dp[0] = 1;

        for(char c : s) {
            for(int j = m; j >= 1; j--) {
                if(c == t[j - 1])
                    dp[j] = min(2147483647LL, dp[j] + dp[j - 1]);
            }
        }

        return dp[m];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna