class Queue {
private:
    stack<int> s;
    void restore(stack<int>& ss) {
        while(!ss.empty()) {
            s.push(ss.top());
            ss.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> ss;
        while(!s.empty()) {
            int u = s.top();
            s.pop();
            if(!s.empty())
                ss.push(u);
        }
        restore(ss);
    }

    // Get the front element.
    int peek(void) {
        stack<int> ss;
        int ans;
        while(!s.empty()) {
            ans = s.top();
            s.pop();
            ss.push(ans);
        }
        restore(ss);
        return ans;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
