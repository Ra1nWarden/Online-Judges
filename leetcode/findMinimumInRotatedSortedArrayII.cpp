class Solution {
private:
    int findMinBin(vector<int> &num, int start, int end) {
        if(start == end)
            return num[start];
        else {
            int mid = (start + end) / 2;
            int leftUpper = mid;
            while(leftUpper > start) {
                if(num[leftUpper] != num[mid])
                    break;
                leftUpper--;
            }
            int rightLower = mid;
            while(rightLower < end) {
                if(num[rightLower] != num[mid])
                    break;
                rightLower++;
            }
            
            if(num[mid] == num[leftUpper]) {
                if(num[mid] == num[rightLower]) {
                    return num[end];
                } else {
                    if(num[rightLower] < num[mid])
                        return num[rightLower];
                    else
                        return min(num[mid], findMinBin(num, rightLower, end));
                } 
            } else {
                if(num[mid] == num[rightLower]) {
                    return min(num[end], findMinBin(num, start, leftUpper));
                } else {
                    if(num[mid] < num[rightLower] && num[mid] < num[leftUpper])
                        return num[mid];
                    else
                        return min(findMinBin(num, start, leftUpper), findMinBin(num, rightLower, end));
                }
            }
        }
    }
public:
    int findMin(vector<int> &num) {
        return findMinBin(num, 0, num.size()-1);
    }
};
