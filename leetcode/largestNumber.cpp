bool _cmp(const string& a, const string& b) {
    for(int i = 0; i < min(a.length(), b.length()); i++) {
        if(a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_strs;
        for(int i = 0; i < nums.size(); i++) {
            stringstream ss;
            ss << nums[i];
            string num_str = ss.str();
            num_strs.push_back(num_str);
        }
        sort(num_strs.begin(), num_strs.end(), _cmp);
        string ans = "";
        for(int i = 0; i < num_strs.size(); i++) {
            ans += num_strs[i];
        }
        int cut = 0;
        for(; cut < ans.length() - 1; cut++) {
            if(ans[cut] != '0')
                break;
        }
        return ans.substr(cut);
    }
};
