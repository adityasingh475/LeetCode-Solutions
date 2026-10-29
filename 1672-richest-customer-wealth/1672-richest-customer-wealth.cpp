class Solution {
public:
    int maximumWealth(vector<vector<int>>& nums) {
         int n=nums.size();
         int m=nums[0].size();

         int max=0;
         for(int i=0;i<n;i++){
          int sum=0;
          for(int j=0;j<m;j++){
           sum+=nums[i][j];
           max=std::max(sum,max);

         }
         
    }
        return max;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna