class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(), 
        z=find(nums.begin(), nums.end(), 0)-nums.begin();
        auto check=[&](int s) {
            for (int i=1; i<n; i++)
                if (nums[(z+i*s+n)%n]<nums[(z+(i-1)*s+n)%n])
                    return false;
            return true;
        };

        int ans=INT_MAX;
        if (check(1)) ans=min({ans, z, n-z+2});
        if (check(-1)) ans=min({ans, z+2, n-z});

        return ans==INT_MAX?-1:ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna