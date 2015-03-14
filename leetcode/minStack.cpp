class MinStack {
private:
    stack<int> min;
    stack<int> s;
public:
    void push(int x) {
        s.push(x);
        if(min.empty() || x <= min.top())
            min.push(x);
    }

    void pop() {
        if(s.empty())
            return;
        int next = s.top();
        s.pop();
        if(!min.empty() && next == min.top())
            min.pop();
    }

    int top() {
      if(s.empty())
	    return false;
      return s.top();
    }

    int getMin() {
      if(min.empty())
	    return false;
      return min.top();
    }
};
