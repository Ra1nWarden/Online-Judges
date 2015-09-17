class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i < nums.size(); i++) {
           int start = i;
           int end = start + 1;
           for(; end < nums.size(); end++) {
               if(nums[end] != nums[end-1] + 1) {
                   end--;
                   break;
               }
           }
           if(end == nums.size()) {
               end--;
           }
           stringstream ss;
           if(start == end) {
               ss << nums[start];
           } else {
               ss << nums[start] << "->" << nums[end];
           }
           ans.push_back(ss.str());
           i = end;
        }
        return ans;
    }
};
