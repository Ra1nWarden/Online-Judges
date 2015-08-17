class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if(sum % 2) {
            return findKth(nums1, nums2, sum / 2 + 1);
        } else {
            return (findKth(nums1, nums2, sum / 2) + findKth(nums1, nums2, sum / 2 + 1)) / 2.0;
        }
    }
    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() > nums2.size())
            return findKth(nums2, nums1, k);
        if(nums1.empty()) {
            return nums2[k-1];
        }
        if(k == 1) {
            return min(nums1[0], nums2[0]);
        }
        int ai = min(k / 2, (int) nums1.size());
        int bi = k - ai;
        if(nums1[ai - 1] < nums2[bi - 1]) {
            vector<int> cpy(nums1.begin() + ai, nums1.end());
            return findKth(cpy, nums2, k - ai);
        } else if(nums1[ai - 1] > nums2[bi - 1]) {
            vector<int> cpy(nums2.begin() + bi, nums2.end());
            return findKth(nums1, cpy, k - bi);
        } else {
            return nums1[ai - 1];
        }
    }
};
