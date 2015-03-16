class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() < 3)
            return res;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; i++) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            for(int j = i+1; j < num.size() - 1; j++) {
                if(j > i+1 && num[j] == num[j-1])
                    continue;
                int sum = num[i] + num[j];
                int target = -sum;
                if(target < num[j])
                    break;
                vector<int>::iterator itr = find(num.begin() + j + 1, num.end(), target);
                if(itr != num.end()) {
                    vector<int> subres;
                    subres.push_back(num[i]);
                    subres.push_back(num[j]);
                    subres.push_back(*itr);
                    res.push_back(subres);
                }
            }
        }
        return res;
    }
};
