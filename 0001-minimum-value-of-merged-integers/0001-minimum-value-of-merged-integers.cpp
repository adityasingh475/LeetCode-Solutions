class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        long long ans=LLONG_MAX;
        for(int i=0;i<nums.size();i+=2){
        long long num=stoll(to_string(nums[i])+to_string(nums[i+1]));
        ans=min(ans,num);
    }
    return ans;
    }     
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna