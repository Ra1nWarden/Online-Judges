class Solution {
private:
    vector<vector<int> > helper(vector<int>& candidates, int start, int target, int head) {
        vector<vector<int> > res;
        if(target == 0) {
            vector<int> v;
            v.push_back(head);
            res.push_back(v);
            return res;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target)
                break;
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            vector<vector<int> > subres = helper(candidates, i + 1, target - candidates[i], candidates[i]);
            for(int j = 0; j < subres.size(); j++) {
                vector<int> combined;
                combined.push_back(head);
                for(int k = 0; k < subres[j].size(); k++)
                    combined.push_back(subres[j][k]);
                res.push_back(combined);
            }
        }
        return res;
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        for(int i = 0; i < candidates.size(); i++) {
            if(candidates[i] > target)
                break;
            if(i > 0 && candidates[i] == candidates[i-1])
                continue;
            vector<vector<int> > subres = helper(candidates, i + 1, target - candidates[i], candidates[i]);
            for(int j = 0; j < subres.size(); j++)
                res.push_back(subres[j]);
        }
        return res;
    }
};
