class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
        int x=nums[i];
         int sum=0;
         while(x>0){
            sum+=x%10;
            x/=10;
         }
        if(sum==i){
            return i;
        }
    }    
        return -1;
    }    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna