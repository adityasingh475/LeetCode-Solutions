
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool ok = true;
            int prev = 0;

            for (int i = 0; i < n; i += k) {
                int mn = nums[i], mx = nums[i], d = 0;

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    int next = (j + 1 == i + k) ? i : j + 1;
                    if (nums[j] > nums[next]) d++;
                }

                if (d > 1 || (i && prev > mn)) {
                    ok = false;
                    break;
                }

                prev = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna