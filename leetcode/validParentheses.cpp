class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == ')' || c == ']' || c == '}') {
                if(st.empty())
                    return false;
                if(c == ')' && st.top() != '(')
                    return false;
                if(c == ']' && st.top() != '[')
                    return false;
                if(c == '}' && st.top() != '{')
                    return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
