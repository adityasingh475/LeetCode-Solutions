#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        
        for(int i = 0; i < nums1.size(); i++) {
            bool found = false;
            
            
            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) {
                    
                    for(int k = j + 1; k < nums2.size(); k++) {
                        if(nums2[k] > nums1[i]) {
                            result.push_back(nums2[k]);
                            found = true;
                            break;
                        }
                    }
                    break; 
                }
            }
            
            
            if(!found) {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna