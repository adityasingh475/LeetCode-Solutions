class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b){
            return -1;
        }
        return max(a.size(),b.size());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna