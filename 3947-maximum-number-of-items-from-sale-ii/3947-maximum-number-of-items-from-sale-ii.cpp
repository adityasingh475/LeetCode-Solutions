class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0, minPrice = INT_MAX;

        for (auto& x : items) {
            mx = max(mx, x[0]);
            minPrice = min(minPrice, x[1]);
        }

        vector<int> freq(mx + 1, 0), gain(mx + 1, 0);

        for (auto& x : items)
            freq[x[0]]++;

        for (int f = 1; f <= mx; f++) {
            for (int j = f; j <= mx; j += f)
                gain[f] += freq[j];

            gain[f]--;
        }

        sort(items.begin(), items.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;

        for (auto& x : items) {
            int f = x[0], p = x[1];

            if (p >= 2LL * minPrice)
                break;

            if (gain[f] <= 0)
                continue;

            int take = min(gain[f], budget / p);

            ans += 2LL * take;
            budget -= take * p;
        }

        ans += budget / minPrice;

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna