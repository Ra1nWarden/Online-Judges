class Solution {
private:
    void subsets(vector<vector<int> >& ans, vector<int>& nums) {
        if(nums.empty()) {
            vector<int> ev;
            ans.push_back(ev);
            return;
        }
        int add_num = nums.back();
        nums.pop_back();
        subsets(ans, nums);
        vector<vector<int> > add;
        for(vector<vector<int> >::iterator itr = ans.begin(); itr != ans.end(); itr++) {
            vector<int> copy = *itr;
            copy.push_back(add_num);
            add.push_back(copy);
        }
         for(vector<vector<int> >::iterator itr = add.begin(); itr != add.end(); itr++) {
            ans.push_back(*itr);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        subsets(ans, nums);
        return ans;
    }
};
