class Solution {
public:
    void reverseString(vector<char>& s) {
        // Create a stack to store characters (Last In First Out - LIFO)
        stack<char> st;

        // Push all characters of the vector onto the stack
        for (char c : s) {
            st.push(c);
        }

        // Pop all characters from the stack and write them back to
        // the vector from the beginning (index 0). This reverses the string.
        int i = 0;
        while (!st.empty()) {
            s[i++] = st.top();
            st.pop();
        }
    }
};

// Alternative Version using stack<int> and index-based loop:
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         stack<int>st; // Stack storing ASCII integer values of characters
//         for(int i=0;i<s.size();i++)
//             st.push(s[i]); // Push characters (implicitly cast to int)
//         
//         int i=0;
//         while(!st.empty()){
//             s[i]=st.top(); // Retrieve top integer and cast back to char
//             i++;
//             st.pop();
//         }
//     }
// };