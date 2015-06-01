class Solution {
public:
    string addBinary(string a, string b) {
        string ans(max(a.length(), b.length()) + 1, '0');
        bool carry = false;
        for(int i = 0; i < ans.length(); i++) {
            int sum = 0;
            if(i < a.length())
                sum += a[a.length() - 1 - i] - '0';
            if(i < b.length())
                sum += b[b.length() - 1 - i] - '0';
            if(carry)
                sum++;
            ans[ans.length() - 1 - i] += (sum % 2);
            carry = sum / 2;
        }
        if(ans[0] == '0')
            return ans.substr(1);
        else
            return ans;
    }
};
