class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(char c : s){
            if(!st.empty() && st.top() == c){
                st.pop();  // remove duplicate
            } else {
                st.push(c);
            }
        }

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};