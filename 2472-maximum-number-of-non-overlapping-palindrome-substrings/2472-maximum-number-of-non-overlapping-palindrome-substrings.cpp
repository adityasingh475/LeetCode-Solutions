class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i + k <= n; ) {
            bool found = false;
            
            if (isPal(s, i, i + k - 1)) {
                ans++;
                i += k;
                found = true;
            }
            
            else if (i + k < n && isPal(s, i, i + k)) {
                ans++;
                i += k + 1;
                found = true;
            }
            if (!found) i++;
        }
        return ans;
    }
    
    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna