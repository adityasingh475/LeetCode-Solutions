class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n=nums.size();
      stack<int> st;
      vector<int> ans(n,-1);
      for(int i=2*n-1;i>=0;i--){
        while(!st.empty()&& st.top()<=nums[i%n]){
            st.pop();
        }
        if(i<n){
            ans[i]=st.empty()?-1:st.top();
        }
        st.push(nums[i%n]);

      }
      return ans;
    }
};        

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna