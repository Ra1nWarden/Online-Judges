typedef pair<int, int> II;

class Comp {
public:
    bool operator()(const II& a, const II& b) {
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<II, vector<II>, Comp> pq;
        for(int i = 0; i < ratings.size(); i++) {
            pq.push(make_pair(ratings[i], i));
        }
        int ans = 0;
        vector<int> candies(ratings.size(), 0);
        while(!pq.empty()) {
            II u = pq.top();
            pq.pop();
            int candy = 1;
            if(u.second - 1 > -1 && ratings[u.second - 1] < u.first && candies[u.second - 1])
                candy = max(candy, candies[u.second - 1] + 1);
            if(u.second + 1 < ratings.size() && ratings[u.second + 1] < u.first && candies[u.second + 1])
                candy = max(candy, candies[u.second + 1] + 1);
            ans += candy;
            candies[u.second] = candy;
        }
        return ans;
    }
};
