class Solution {
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto convert = [&](string s) {
            int m = stoi(s.substr(0,2));
            int d = stoi(s.substr(3,2));
            for(int i = 0; i < m - 1; i++)
                d += days[i];
            return d;
        };

        int start = max(convert(aA), convert(aB));
        int end = min(convert(lA), convert(lB));

        return max(0, end - start + 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna