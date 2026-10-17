class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> a;

        for (int i = 0; i < n; i++) {
            int x = nums[i], s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            a.push_back({s, nums[i]});
        }

        sort(a.begin(), a.end());

        unordered_map<int,int> pos;
        for (int i = 0; i < n; i++)
            pos[a[i].second] = i;

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) 
             continue;

            int j = i, cnt = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                cnt++;
            }
            ans += max(0, cnt - 1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna