class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if (is_sorted(s.begin(), s.end())) 
          return 0;
        if (n==2) 
          return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0]==mn || s[n-1]==mx) 
          return 1;

        for (int i=1; i<n-1; i++)
            if (s[i]==mn || s[i]==mx) 
             return 2;

        return 3;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna