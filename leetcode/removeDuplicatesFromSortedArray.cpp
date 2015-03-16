class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 2)
            return n;
        int res = 1;
        int index = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] == A[i-1])
                continue;
            A[index++] = A[i];
            res++;
        }
        return res;
    }
};
