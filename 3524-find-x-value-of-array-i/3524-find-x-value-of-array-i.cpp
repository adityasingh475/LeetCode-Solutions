class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (int x : nums) {
            vector<long long> next(k);
            int r = x % k;

            next[r] = 1;

            for (int i = 0; i < k; i++)
                next[(i * r) % k] += dp[i];

            for (int i = 0; i < k; i++)
                ans[i] += next[i];

            dp = next;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna