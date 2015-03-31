class Solution {
public:
    void findPermutateUnique(vector<vector<int> >& res, vector<int> subres, map<int, int>& m, int n) {
        if(subres.size() == n)
            res.push_back(subres);
        for(map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
            if(itr->second != 0) {
                vector<int> subcopy = subres;
                subcopy.push_back(itr->first);
                int val = itr->second;
                m[itr->first] = val - 1;
                findPermutateUnique(res, subcopy, m, n);
                m[itr->first] = val;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        map<int, int> m;
        for(int i = 0; i < num.size(); i++) {
            if(m.count(num[i]) == 0)
                m[num[i]] = 1;
            else
                m[num[i]] = m[num[i]] + 1;
        }
        vector<int> subres;
        findPermutateUnique(res, subres, m, num.size());
        return res;
    }
};
