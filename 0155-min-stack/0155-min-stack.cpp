class MinStack{
    stack<pair<int,int>> st;
public:
    void push(int value){
        if(st.empty()){
            st.push({value,value});
        }
        else{
            st.push({value,min(value,st.top().second)});
        }
    }    
    int getMin(){
       return st.top().second;
    }    
    void pop(){
       st.pop();
    }
    int top(){
       return st.top().first;
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna