class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> v;
        v.push_back(1);
        while(v.size() != n) {
            int next = min(v[i] * 2, min(v[j] * 3, v[k] * 5));
            if(next == v[i] * 2)
                i++;
            if(next == v[j] * 3)
                j++;
            if(next == v[k] * 5)
                k++;
            v.push_back(next);
        }
        return v.back();
    }
};
