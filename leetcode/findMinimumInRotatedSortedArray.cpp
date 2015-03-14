class Solution {
private:
    int findMinBin(vector<int>& vec, int start, int end) {
        if(start == end) {
            return vec[start];
        } else {
            int mid = (start + end) / 2;
            if(vec[mid+1] < vec[mid])
                return vec[mid+1];
            if(mid - 1 >= start) {
                if(vec[mid-1] > vec[mid])
                    return vec[mid];
                else
                    return min(findMinBin(vec, start, mid - 1), findMinBin(vec, mid+1, end));
            }
            else
                return min(vec[mid], findMinBin(vec, mid+1, end));
        }
    }
public:
    int findMin(vector<int> &num) {
        return findMinBin(num, 0, num.size() - 1);
    }
};
