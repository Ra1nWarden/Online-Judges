class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.size() < 4)
            return res;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 3; i++) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            long long sum = num[i];
            long long left = target - sum;
            if(left < num[i] * 3)
                break;
            for(int j = i+1; j < num.size() - 2; j++) {
                if(j > i+1 && num[j] == num[j-1])
                    continue;
                sum = num[i] + num[j];
                left = target - sum;
                if(left < num[j] * 2)
                    break;
                int k = j + 1;
                int l = num.size() - 1;
                while(k < l) {
                    if(num[k] + num[l] > left) {
                        l--;
                        while(num[l+1] == num[l] && l > k)
                            l--;
                    } else if(num[k] + num[l] < left) {
                        k++;
                        while(num[k] == num[k-1] && k < l)
                            k++;
                    } else {
                        vector<int> subres;
                        subres.push_back(num[i]);
                        subres.push_back(num[j]);
                        subres.push_back(num[k]);
                        subres.push_back(num[l]);
                        res.push_back(subres);
                        k++;
                        l--;
                        while(num[k] == num[k-1] && num[l+1] == num[l] && k < l) {
                            k++;
                            l--;
                        }
                    }
                }
            }
        }
        return res;
    }
};
