class Solution {
private:
    string sep[4] = {"", "Thousand", "Million", "Billion"};
    string ones[10] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    string onetens[9] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> read(int rank, int number) {
        vector<string> ans;
        if(number >= 100) {
            int hundreds = number / 100;
            number %= 100;
            ans.push_back(ones[hundreds - 1]);
            ans.push_back("Hundred");
        }
        if(number >= 20) {
            int tenss = number / 10;
            number %= 10;
            ans.push_back(tens[tenss - 2]);
        }
        if(number > 10) {
            ans.push_back(onetens[number - 11]);
            number = 0;
        }
        if(number > 0) {
            ans.push_back(ones[number - 1]);
            number = 0;
        }
        if(rank > 0 && !ans.empty())
            ans.push_back(sep[rank]);
        return ans;
    }
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        vector<int> nums;
        while(num) {
            nums.push_back(num % 1000);
            num /= 1000;
        }
        string ans = "";
        for(int i = nums.size() - 1; i >= 0; i--) {
            vector<string> sub = read(i, nums[i]);
            for(int j = 0; j < sub.size(); j++) {
                if(!ans.empty())
                    ans += " ";
                ans += sub[j];
            }
        }
        return ans;
    }
};
