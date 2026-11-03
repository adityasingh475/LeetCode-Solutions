class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxim=nums[0];
        for(int i=0;i<n;i++){
            maxim=max(maxim,nums[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            while(nums[i]<maxim){
                nums[i]++;
                count++;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna