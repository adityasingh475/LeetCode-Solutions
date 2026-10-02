class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        function<void(string, int, int)> solve = [&](string s, int open, int close) {
            if (s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }

            if (open < n)
                solve(s + "(", open + 1, close);

            if (close < open)
                solve(s + ")", open, close + 1);
        };

        solve("", 0, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna