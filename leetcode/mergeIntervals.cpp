/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool cmp(Interval& a, Interval& b) {
     if(a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
 }
 
 Interval mergeInterval(Interval& a, Interval& b) {
     Interval ans;
     ans.start = min(a.start, b.start);
     ans.end = max(a.end, b.end);
     return ans;
 }
 
 bool mergable(Interval& a, Interval& b) {
     return b.start <= a.end;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.empty())
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            Interval next = intervals[i];
            if(mergable(prev, next)) {
                prev = mergeInterval(prev, next);
            } else {
                ans.push_back(prev);
                prev = next;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
