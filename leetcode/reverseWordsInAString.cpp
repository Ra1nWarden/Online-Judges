#include <sstream>
#include <stack>

class Solution {
public:
    void reverseWords(string &s) {
        istringstream iss(s.c_str());
        stack<string> st;
        string word;
        while(iss >> word) {
            st.push(word);
        }
        string result = "";
        while(!st.empty()) {
            string next = st.top();
            st.pop();
            if(!st.empty())
                result = result + next + " ";
            else
                result = result + next;
        }
        s = result;
    }
};
