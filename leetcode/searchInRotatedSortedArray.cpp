class Solution {
public:
    int helper(int A[], int target, int start, int end) {
        if(start == end)
            return A[start] == target ? start : -1;
        if(end < start)
            return -1;
        int mid = (start + end) >> 1;
        if(A[mid] == target)
            return mid;
        if(A[end] > A[start]) {
            return A[mid] > target ? helper(A, target, start, mid-1) : helper(A, target, mid+1, end);
        } else {
            if(A[mid] >= A[start])
                if(A[mid] < target)
                    return helper(A, target, mid+1, end);
                else
                    return A[start] <= target ? helper(A, target, start, mid-1) : helper(A, target, mid+1, end); 
            else
                if(A[mid] > target)
                    return helper(A, target, start, mid-1);
                else
                    return A[end] < target ? helper(A, target, start, mid-1) : helper(A, target, mid+1, end);
        }
    }
    int search(int A[], int n, int target) {
        return helper(A, target, 0, n-1);
    }
};
