class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n=asteroids.size();
        for (int i=0; i<n; i++) {
            int a=asteroids[i];
            bool alive=true;

            while (alive && a<0 && !st.empty() && st.back()>0) {
                if (st.back()<-a)
                    st.pop_back();
                else {
                    if (st.back()==-a)
                        st.pop_back();
                    alive=false;
                }
            }

            if (alive)
                st.push_back(a);
        }

        return st;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna