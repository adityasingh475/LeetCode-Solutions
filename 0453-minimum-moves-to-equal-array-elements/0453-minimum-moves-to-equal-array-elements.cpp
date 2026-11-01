class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int mini=INT_MAX;
        for(int x:nums){
            sum+=x;
            mini=min(mini,x);
        }
      return sum-nums.size()*mini;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna