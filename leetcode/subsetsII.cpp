class Solution {
private:
    map<int, int> m;
public:
    void solve(vector<vector<int> >& ans, vector<int> sub, map<int, int>::iterator itr) {
        if(itr == m.end()) {
            ans.push_back(sub);
            return;
        }
        if(itr->second > 0) {
            itr->second--;
            vector<int> subcopy = sub;
            subcopy.push_back(itr->first);
            solve(ans, subcopy, itr);
            itr->second++;
        }
        solve(ans, sub, ++itr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> each;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else
                m[nums[i]] = m[nums[i]] + 1;
        }
        map<int, int>::iterator itr = m.begin();
        solve(ans, each, itr);
        return ans;
    }
};
