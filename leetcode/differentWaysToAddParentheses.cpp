class Solution {
private:
    vector<string> parse(string input) {
        vector<string> ans;
        string token = "";
        for(int i = 0; i < input.length(); i++) {
            if(isdigit(input[i])) {
                if(token.empty() || isdigit(token[0])) {
                    token += input[i];
                } else {
                    ans.push_back(token); 
                    token = input[i];
                }
            } else {
                ans.push_back(token);
                token = input[i];
            }
        }
	ans.push_back(token);
        return ans;
    }
    vector<int> helper(vector<string> tokens) {
        vector<int> ans;
        if(tokens.size() == 1) {
            ans.push_back(atoi(tokens[0].c_str()));
            return ans;
        }
        for(int i = 1; i < tokens.size(); i+=2) {
            vector<string> left_side(tokens.begin(), tokens.begin() + i);
            vector<int> left = helper(left_side);
            vector<string> right_side(tokens.begin() + 1 + i, tokens.end());
            vector<int> right = helper(right_side);
            for(int ii = 0; ii < left.size(); ii++) {
                for(int jj = 0; jj < right.size(); jj++) {
                    if(tokens[i] == "+") {
                        ans.push_back(left[ii] + right[jj]);
                    } else if(tokens[i] == "-") {
                        ans.push_back(left[ii] - right[jj]);
                    } else {
                        ans.push_back(left[ii] * right[jj]);
                    }
                }
            }  
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        vector<string> tokens = parse(input);
        return helper(tokens);
    }
};
