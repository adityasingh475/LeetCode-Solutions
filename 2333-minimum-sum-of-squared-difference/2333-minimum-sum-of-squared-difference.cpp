
class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> d;
        long long sum = 0;

        for (int i = 0; i < a.size(); i++) {
            d.push_back(abs(a[i] - b[i]));
            sum += d.back();
        }

        if (sum <= k) return 0;

        long long l = 0, r = 1000000000LL;

        while (l < r) {
            long long mid = (l + r) / 2;
            long long need = 0;

            for (long long x : d)
                need += max(0LL, x - mid);

            if (need <= k) r = mid;
            else l = mid + 1;
        }

        long long ans = 0;

        for (long long x : d) {
            long long y = min(x, l);
            ans += y * y;
            k -= x - y;
        }

        for (long long x : d) {
            if (k > 0 && x >= l && x > 0) {
                ans -= 2 * l - 1;
                k--;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna