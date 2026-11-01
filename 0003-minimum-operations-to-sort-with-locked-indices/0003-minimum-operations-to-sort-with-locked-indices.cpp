class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int need=0, mx=0, start=0;

        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);

            if(mx==i+1){
                if(i>start){
                    for(int j=start;j<=i;j++){
                        need+=locked[j];
                    }
                }
                start=i+1;
            }
        }
        if(need>k)
          return -1;
        vector<int>bit(n+1,0);
        long long swaps=0;

        for(int i=0;i<n;i++){
            int x=nums[i];

            int sum=0;
            for(int j=x;j>0;j-=j&-j)
             sum+=bit[j];

            swaps+=i-sum;

            for(int j=x;j<=n;j+=j&-j)
             bit[j]++;
            
        }
        return swaps+need;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna