class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(1);
        unordered_set<long long> vis;
        vis.insert(1);
        while(n > 1) {
            int u = pq.top();
            pq.pop();
            for(int j = 0; j < primes.size(); j++) {
                if(INT_MAX / u < primes[j])
                    break;
                int v = primes[j] * u;
                if(vis.count(v))
                    continue;
                vis.insert(v);
                pq.push(v);
            }
            n--;
        }
        return pq.top();
    }
};
