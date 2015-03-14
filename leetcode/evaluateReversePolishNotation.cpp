#include <stack>
#include <cstdlib>

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        for(int i= 0; i < tokens.size(); i++) {
            string next = tokens[i];
            if(next == "+") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b+a);
            }
            else if(next == "-") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b-a);
            }
            else if(next == "*") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a*b);
            }
            else if(next == "/") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b/a);
            }
            else {
                int nextNum = atoi(next.c_str());
                nums.push(nextNum);
            }
        }
        return nums.top();
    }
};
