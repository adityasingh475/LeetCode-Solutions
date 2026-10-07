class Solution {
public:
    vector<string> ans;

    void solve(string &s, int start, int l, int r, int open) {
        if(l == 0 && r == 0) {
            string t;
            int cnt = 0;

            for(char c : s) {
                if(c == '(') cnt++;
                else if(c == ')') {
                    if(cnt == 0) return;
                    cnt--;
                }
            }

            if(cnt == 0)
                ans.push_back(s);

            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(i > start && s[i] == s[i-1])
                continue;

            if(l + r > s.size() - i)
                return;

            if(l > 0 && s[i] == '(') {
                char c = s[i];
                s.erase(i, 1);
                solve(s, i, l - 1, r, open);
                s.insert(i, 1, c);
            }

            if(r > 0 && s[i] == ')') {
                char c = s[i];
                s.erase(i, 1);
                solve(s, i, l, r - 1, open);
                s.insert(i, 1, c);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;

        for(char c : s) {
            if(c == '(')
                l++;
            else if(c == ')') {
                if(l > 0)
                    l--;
                else
                    r++;
            }
        }

        solve(s, 0, l, r, 0);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna