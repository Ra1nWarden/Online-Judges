class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool done = false;
        for(int i = digits.size() - 1; i > -1; i--) {
            if(digits[i] != 9) {
                digits[i] = digits[i] + 1;
                done = true;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if(!done) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
