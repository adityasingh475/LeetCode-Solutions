class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> l, r;
        long long a = 0, b = 0;
        vector<long long> cost;

        auto balance = [&]() {
            while (l.size() > r.size() + 1) {
                int v = *l.rbegin();
                l.erase(l.find(v));
                a -= v;
                r.insert(v);
                b += v;
            }
            while (l.size() < r.size()) {
                int v = *r.begin();
                r.erase(r.find(v));
                b -= v;
                l.insert(v);
                a += v;
            }
        };

        for (int i = 0; i < n; i++) {
            if (l.empty() || nums[i] <= *l.rbegin()) {
                l.insert(nums[i]);
                a += nums[i];
            } else {
                r.insert(nums[i]);
                b += nums[i];
            }

            if (i >= x) {
                int v = nums[i - x];
                if (l.find(v) != l.end()) {
                    l.erase(l.find(v));
                    a -= v;
                } else {
                    r.erase(r.find(v));
                    b -= v;
                }
            }

            balance();

            if (i >= x - 1) {
                long long m = *l.rbegin();
                cost.push_back(m * l.size() - a + b - m * r.size());
            }
        }

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 1e18));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x)
                    dp[j][i] = min(dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]);
            }
        }

        return dp[k][n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna