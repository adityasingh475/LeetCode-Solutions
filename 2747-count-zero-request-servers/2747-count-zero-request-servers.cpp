class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();
        vector<pair<int, int>> qs;

        for (int i = 0; i < m; i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        vector<int> ans(m);
        unordered_map<int, int> freq;

        int left = 0, right = 0;
        int active = 0;

        for (auto &[q, idx] : qs) {
            int L = q - x;

            while (right < logs.size() && logs[right][1] <= q) {
                int server = logs[right][0];

                if (++freq[server] == 1)
                    active++;

                right++;
            }

            while (left < right && logs[left][1] < L) {
                int server = logs[left][0];

                if (--freq[server] == 0) {
                    freq.erase(server);
                    active--;
                }

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna