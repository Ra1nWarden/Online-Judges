class MedianFinder {
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int> > upper;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower.empty()) {
            lower.push(num);
            return;
        }
        if(upper.empty()) {
            int lower_num = lower.top();
            if(num > lower_num) {
                upper.push(num);
            } else {
                lower.pop();
                lower.push(num);
                upper.push(lower_num);
            }
            return;
        }
        int lower_num = lower.top();
        int upper_num = upper.top();
        if(lower.size() < upper.size()) {
            if(num < upper_num) {
                lower.push(num);
            } else {
                upper.pop();
                upper.push(num);
                lower.push(upper_num);
            }
        } else if(lower.size() == upper.size()) {
            if(num > upper_num) {
                upper.push(num);
            } else {
                lower.push(num);
            }
        } else {
            if(num > lower_num) {
                upper.push(num);
            } else {
                lower.pop();
                lower.push(num);
                upper.push(lower_num);
            }
        }
    }
    
    double findMedian() {
        if(lower.size() < upper.size()) {
            return upper.top();
        } else if(lower.size() == upper.size()) {
            return (lower.top() + upper.top()) / 2.0;
        } else {
            return lower.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
