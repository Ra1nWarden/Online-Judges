class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        map<int, int> m;
        for(int i = 0; i < numbers.size(); i++) {
            int match = target - numbers[i];
            if(m.count(match)) {
                res.push_back(m[match]);
                res.push_back(i+1);
                return res;
            }
            m[numbers[i]] = i+1;
        }
    }
};
