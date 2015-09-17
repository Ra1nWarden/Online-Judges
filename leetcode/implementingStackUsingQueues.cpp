class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> qq;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(!q.empty())
                qq.push(u);
        }
        q = qq;
    }

    // Get the top element.
    int top() {
        queue<int> qq;
        int ans;
        while(!q.empty()) {
            ans = q.front();
            q.pop();
            qq.push(ans);
        }
        q = qq;
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
