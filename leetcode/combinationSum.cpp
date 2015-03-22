#include <bits/stdc++.h>

using namespace std;

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
            vector<vector<int> > subres = helper(candidates, i, target - candidates[i], candidates[i]);
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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        for(int i = 0; i < candidates.size(); i++) {
            if(candidates[i] > target)
                break;
            vector<vector<int> > subres = helper(candidates, i, target - candidates[i], candidates[i]);
            for(int j = 0; j < subres.size(); j++)
                res.push_back(subres[j]);
        }
        return res;
    }
};

int main() {
  vector<int> v;
  v.push_back(2);
  v.push_back(3);
  v.push_back(6);
  v.push_back(7);
  Solution sol;
  vector<vector<int> > res = sol.combinationSum(v, 7);
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
