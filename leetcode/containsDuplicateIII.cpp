typedef pair<int, int> II;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<II> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++) {
            II test = make_pair(v[i].first - t, -1);
            int j = lower_bound(v.begin(), v.begin() + i, test) - v.begin();
            for(; j < i; j++) {
                if(abs(v[j].second - v[i].second) <= k)
                    return true;
            }
        }
        return false;
    }
};
