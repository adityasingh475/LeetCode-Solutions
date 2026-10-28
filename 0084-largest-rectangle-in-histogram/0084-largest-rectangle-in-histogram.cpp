class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxArea=0;

        for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int h=heights[st.top()];
            st.pop();

         int width;
         if(st.empty())
           width=i;     
         else
            width=i-st.top()-1;
            maxArea=max(maxArea,h*width);
         }  
         st.push(i);
        }

         while (!st.empty()) {
            int h=heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width=n;
            else
                width=n-st.top()-1;

            maxArea=max(maxArea, h*width);
        }

        return maxArea;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna