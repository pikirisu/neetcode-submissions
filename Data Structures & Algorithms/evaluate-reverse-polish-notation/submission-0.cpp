class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int count =0;
        for(int i=0;i<tokens.size();i++){
            string str = tokens[i];
            if(str=="+" || str=="-" || str=="*" || str=="/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result;
                if (str == "+") result = a + b;
                else if (str == "-") result = a - b;
                else if (str == "*") result = a * b;
                else if (str == "/") result = a / b;
                st.push(result);
            }
            else{
            int pushed = stoi(str);
            st.push(pushed);
            }
        }
        return st.top();
    }
        
};
