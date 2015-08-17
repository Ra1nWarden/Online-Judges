typedef pair<int, int> Bucket;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        if(nums.size() == 2)
            return max(nums[0], nums[1]) - min(nums[0], nums[1]);
        int min_val = nums[0], max_val = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }
        if(max_val == min_val)
            return 0;
        int bucket_size = (max_val - min_val) / (nums.size() - 1) + 1;
        vector<Bucket> buckets((max_val - min_val) / bucket_size + 1);
        for(int i = 0; i < buckets.size(); i++) {
            buckets[i].first = buckets[i].second = -1;
        }
        for(int i = 0; i < nums.size(); i++) {
            int id = (nums[i] - min_val) / bucket_size;
            if(buckets[id].first == -1) {
                buckets[id].first = buckets[id].second = nums[i];
            } else {
                buckets[id].first = min(buckets[id].first, nums[i]);
                buckets[id].second = max(buckets[id].second, nums[i]);
            }
        }
        int ans = -1;
        int prev_max = buckets[0].second;
        for(int i = 1; i < buckets.size(); i++) {
            if(buckets[i].first == -1)
                continue;
            ans = max(ans, buckets[i].first - prev_max);
            prev_max = buckets[i].second;
        }
        return ans;
    }
};
