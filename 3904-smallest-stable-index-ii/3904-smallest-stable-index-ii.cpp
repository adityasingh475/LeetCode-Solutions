class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> right(n);
        
        right[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--)
            right[i] = min(right[i+1], nums[i]);

        int mx = 0;

        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if(mx - right[i] <= k)
                return i;
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna