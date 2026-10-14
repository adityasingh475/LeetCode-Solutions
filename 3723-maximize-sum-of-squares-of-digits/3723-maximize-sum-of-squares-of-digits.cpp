
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }

        if (sum > 0) ans += char('0' + sum);

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna