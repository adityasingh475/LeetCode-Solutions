class Solution {
public:
    bool canAliceWin(int n) {
        int take=10;
        bool aliceTurn=true;

        while (take>0) {
            if (n < take) {
                return !aliceTurn;
            }

            n -= take;
            take--;
            aliceTurn = !aliceTurn;
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna