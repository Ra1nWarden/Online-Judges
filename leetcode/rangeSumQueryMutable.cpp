class NumArray {
private:
    vector<int> orig;
    vector<int> bit;
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int idx, int num) {
        while(idx < bit.size()) {
            bit[idx] += num;
            idx += lowbit(idx);
        }
    }
    int sum(int idx) {
        int ret = 0;
        while(idx > 0) {
            ret += bit[idx];
            idx -= lowbit(idx);
        }
        return ret;
    }

public:
    NumArray(vector<int>& nums) {
        orig = nums;
        for(int i = 0; i < nums.size() + 1; i++) {
            bit.push_back(0);
        }
        for(int i = 0; i < nums.size(); i++) {
            add(i+1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - orig[i];
        add(i + 1, diff);
        orig[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
