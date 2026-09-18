class Solution {
public:
    int findNumbers(vector<int>& nums) { return count_if(nums.begin(), nums.end(), [](int x){ return to_string(x).size()%2==0; }); }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna