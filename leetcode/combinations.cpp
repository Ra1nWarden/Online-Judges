class Solution {
private:
    int n, k;
public:
    void combine(vector<vector<int> >& ans, vector<int> v, int min) {
        if(v.size() == k) {
            ans.push_back(v);
        } else {
            if(v.size() + (n - min) >= k) {
                for(int next = min+1; next <= n; next++) {
                    vector<int> newv = v;
                    newv.push_back(next);
                    combine(ans, newv, next);
                }
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int> > ans;
        vector<int> sub;
        combine(ans, sub, 0);
        return ans;
    }
};
