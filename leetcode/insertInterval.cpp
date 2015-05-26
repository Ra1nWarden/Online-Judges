/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class Solution {
private:
    bool mergable(Interval& a, Interval& b) {
        return (b.start >= a.start && b.start <= a.end) || (a.start >= b.start && a.start <= b.end);
    }
    Interval mergeInterval(Interval& a, Interval& b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        if(intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        bool inserted = false;
        bool insert = false;
        for(int i = 0; i < intervals.size(); i++) {
            while(mergable(newInterval, intervals[i]) && i < intervals.size()) {
                insert = true;
                newInterval = mergeInterval(newInterval, intervals[i]);
                i++;
            }
            if(insert) {
                ans.push_back(newInterval);
                insert = false;
                inserted = true;
            }
            if(i < intervals.size()) {
                if(!inserted && newInterval.end < intervals[i].start) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            }
        }
        if(!inserted)
            ans.push_back(newInterval);
        return ans;
    }
};
