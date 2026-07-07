class Solution {
public:
    string removeDuplicates(string s) {
        // Stack to store characters during traversal
        stack<char> st;

        // Traverse each character of the string
        for(char c : s){
            // If stack is not empty and the current character matches
            // the top character of the stack, we found an adjacent duplicate.
            // Pop the matching character to remove it.
            if(!st.empty() && st.top() == c){
                st.pop();  // remove duplicate
            } else {
                // Otherwise, push the current character onto the stack
                st.push(c);
            }
        }

        // Reconstruct the remaining string from the stack
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        // Since elements are popped in reverse (LIFO), reverse the result string
        reverse(res.begin(), res.end());
        return res;
    }
};

// Alternative Version using index-based loop:
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char>st; // Stack to keep track of characters
//         for(int i=0;i<s.size();i++){
//             // Check if stack is not empty and current char matches the top
//             if(!st.empty() && s[i]==st.top())
//                 st.pop(); // Remove the adjacent duplicate
//             else
//                 st.push(s[i]); // Push the non-duplicate character
//         }
//         
//         // Retrieve elements from stack (will be in reverse order)
//         string res = "";
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
// 
//         // Reverse the string to get the correct original order
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };