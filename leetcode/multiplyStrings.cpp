class Solution {
public:
    string mult(string num1, int dig) {
        if(dig == 0)
            return "0";
        if(dig == 1)
            return num1;
        string ans = "";
        int carry = 0;
        for(int i = num1.length() - 1; i > -1; i--) {
            int prod = dig * (num1[i] - '0') + carry;
            carry = prod / 10;
            int res = prod % 10;
            string digs = "0";
            digs[0] = '0' + res;
            ans = digs + ans;
        }
        if(carry > 0) {
            string digs = "0";
            digs[0] = '0' + carry;
            ans = digs + ans;
        }
        return ans;
    }

    string add(string num1, string num2) {
        string ans = "";
        int carry = 0;
        for(int i = 0; i < max(num1.length(), num2.length()); i++) {
            int res = carry + (i < num1.length() ? num1[num1.length() - 1- i] - '0' : 0)
                + (i < num2.length() ? num2[num2.length() -1 - i] - '0' : 0);
            carry = res / 10;
            string dig = "0";
            dig[0] = (res % 10) + '0';
            ans = dig + ans;
        }
        if(carry > 0) {
            string dig = "0";
            dig[0] = '0' + carry;
            ans = dig + ans;
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        string ans = "0";
        for(int i = num1.length() - 1; i > -1; i--) {
            string addup = mult(num2, num1[i] - '0');
            for(int j = 0; j < num1.length() - i - 1; j++)
                addup += "0";
            ans = add(ans, addup);
        }
        int i = 0;
        for(; i < ans.length() - 1; i++) {
            if(ans[i] != '0') {
                break;
            }
        }
        return ans.substr(i);
    }
};
