class Solution {
public:
    void findPermutate(vector<vector<int> >& res, vector<int> subres, bool* used, vector<int> v) {
        if(subres.size() == v.size()) {
            res.push_back(subres);
            return;
        }
        for(int i = 0; i < v.size(); i++) {
            if(!used[i]) {
                vector<int> nextsub = subres;
                nextsub.push_back(v[i]);
                used[i] = true;
                findPermutate(res, nextsub, used, v);
                used[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        bool used[num.size()];
        memset(used, false, sizeof used);
        vector<vector<int> > res;
        if(num.empty())
            return res;
        vector<int> subres;
        findPermutate(res, subres, used, num);
        return res;
    }
};
