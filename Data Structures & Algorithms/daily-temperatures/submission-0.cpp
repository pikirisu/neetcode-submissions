class Solution {
public:
    vector<int> nextGreater(vector<int>& tempratures){
        stack<int>st;
        int n = tempratures.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && tempratures[st.top()]<=tempratures[i]){
                st.pop();
            }
            if(!st.empty())
            ans[i]=st.top()-i;
            else ans[i]=0;
            st.push(i);
        }
        return ans; 
    }
    // vector<int> prevGreater(vector<int>& tempratures){
    //     stack<int>st;
    //     int n = tempratures.size();
    //     vector<int>ans(n,n);
    //     for(int i=0;i<n;i++){
    //         while(!st.empty() && st.top()<=tempratures[i]){
    //             st.pop();
    //         }
    //         if(!st.empty())
    //         ans.push_back(st.top());
    //         else ans.push_back(0);
    //         st.push(i);
    //     }
    //     return ans;
    // }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // vector<int>prevG = prevGreater(temperatures);
        vector<int>nextG = nextGreater(temperatures);
        return nextG;
    }
};
