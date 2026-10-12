
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int cnt[30] = {};

        for (int x : nums)
            for (int b = 0; b < 30; b++)
                if (x & (1 << b))
                    cnt[b]++;

        while (k--) {
            long long x = 0;

            for (int b = 0; b < 30; b++) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna