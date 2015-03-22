class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        int start = lower_bound(A, A+n, target) - A;
        if(start == n || A[start] != target) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else {
            int end = upper_bound(A, A+n, target) - A - 1;
            res.push_back(start);
            res.push_back(end);
            return res;
        }
    }
};
