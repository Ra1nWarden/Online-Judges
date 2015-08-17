class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int ans = -1;
        int total = 0;
        for(int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0) {
                ans = i;
                sum = 0;
            }
        }
        return total >= 0 ? ans + 1 : -1;
    }
};
