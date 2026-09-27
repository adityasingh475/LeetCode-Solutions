class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40,
                       10, 9, 5, 4, 1};

        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                          "X", "IX", "V", "IV", "I"};

        string ans = "";

        for (int i = 0; i < 13; i++) {
            while (num >= value[i]) {
                ans += roman[i];
                num -= value[i];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna