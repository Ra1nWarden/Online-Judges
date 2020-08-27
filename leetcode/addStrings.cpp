class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        for(int i = 0; i < max(num1.length(), num2.length()); i++) {
            int dig1 = i < num1.length() ? (num1[num1.length() - 1 - i] - '0') : 0;
            int dig2 = i < num2.length() ? (num2[num2.length() - 1 - i] - '0') : 0;
            int sum = dig1 + dig2 + carry;
            carry = sum / 10;
            int dig = sum % 10;
            ans.push_back(('0' + dig));
        }
        if(carry) {
            ans.push_back(('0' + carry));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
