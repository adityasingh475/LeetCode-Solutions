class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=(int)num1.size()-1;
        int j=(int)num2.size()-1;

        int carry=0;
        string ans="";

        while(i>=0||j>=0||carry>0){
            int sum=carry;
            if(i>=0){
                sum=sum+num1[i]-'0';
                i--;
            }    
            if(j>=0){
               sum=sum+num2[j]-'0';
               j--;
            }
            ans=ans+char(sum%10+'0');
            carry=sum/10;   
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna