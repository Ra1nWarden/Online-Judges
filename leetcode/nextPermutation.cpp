class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int swapi = -1;
        for(int i = num.size() - 1; i > 0; i--) {
            if(num[i] > num[i-1]) {
                swapi = i - 1;
                break;
            }
        }
        if(swapi == -1) {
            reverse(num.begin(), num.end());
            return;
        }
        int swapn = num[swapi];
        sort(num.begin() + swapi, num.end());
        int backswap = upper_bound(num.begin() + swapi, num.end(), swapn) - num.begin();
        for(int i = backswap; i > swapi; i--) {
            swap(num[i], num[i-1]);
        }
    }
};
