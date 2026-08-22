class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int sum = 0, product = 1;

        while (x > 0) {
            int digit = x % 10;
            sum += digit;
            product *= digit;
            x /= 10;
        }

        if (n % (sum + product) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna