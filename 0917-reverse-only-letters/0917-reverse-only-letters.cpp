class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0, r=s.size()-1;
        while (l<r) {
            while (l<r && !isalpha(s[l])) 
             ++l;
            while (l<r && !isalpha(s[r])) 
             --r; 
            swap(s[l++],s[r--]);
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna