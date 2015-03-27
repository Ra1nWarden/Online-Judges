#include <queue>
#include <iostream>

using namespace std;

struct Paper {
  Paper() {};
  Paper(long long a, long long b) : grade(a), essay(b) {};
  long long grade;
  long long essay;
  bool operator<(const Paper& another) const {
    return essay > another.essay;
  };
};

int main() {
  long long n, r, av;
  cin >> n >> r >> av;
  long long total = av * n;
  priority_queue<Paper> q;
  for(long long i  = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    total -= a;
    q.push(Paper(a, b));
  }
  long long result = 0;
  while(total > 0 && !q.empty()) {
    Paper next = q.top();
    q.pop();
    long long add = r - next.grade;
    result += min(add, total) * next.essay;
    total -= add;
  }
  cout << result << endl;
  return 0;
}
