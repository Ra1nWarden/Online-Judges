class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = 0;
        bool init = true;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; i++) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            for(int j = i + 1; j < num.size() - 1; j++) {
                if(j > i+1 && num[j] == num[j-1])
                    continue;
                int sum = num[i] + num[j];
                int left = target - sum;
                if(left < num[j]) {
                    int subsum = sum + num[j+1];
                    if(init) {
                        res = subsum;
                        init = false;
                    } else if(abs(subsum - target) < abs(res - target)) {
                        res = subsum;
                    }
                    break;
                }
                vector<int>::iterator itr = lower_bound(num.begin() + j + 1, num.end(), left);
                int subsum = sum + *itr;
                if(init) {
                    res = subsum;
                    init = false;
                } else if(abs(subsum - target) < abs(res - target)) {
                    res = subsum;
                }
                if(itr > num.begin() + j + 1) {
                    itr--;
                    int subsum = sum + *itr;
                    if(abs(subsum - target) < abs(res - target)) {
                        res = subsum;
                    }
                }
            }
        }
        return res;
    }
};
