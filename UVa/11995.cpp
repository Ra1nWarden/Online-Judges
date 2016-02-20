#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
int n;
bool possible[3];

int main() {
  while(scanf("%d", &n) != EOF) {
    memset(possible, true, sizeof possible);
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
      int op, num;
      scanf("%d %d", &op, &num);
      if(op == 1) {
	s.push(num);
	q.push(num);
	pq.push(num);
      } else {
	if(possible[0]) {
	  possible[0] = !s.empty() && s.top() == num;
	  s.pop();
	}
	if(possible[1]) {
	  possible[1] = !q.empty() && q.front() == num;
	  q.pop();
	}
	if(possible[2]) {
	  possible[2] = !pq.empty() && pq.top() == num;
	  pq.pop();
	}
      }
    }
    int cnt = 0;
    for(int i = 0; i < 3; i++) {
      if(possible[i])
	cnt++;
    }
    if(cnt == 0) {
      printf("impossible\n");
    } else if(cnt > 1) {
      printf("not sure\n");
    } else {
      if(possible[0]) {
	printf("stack\n");
      } else if(possible[1]) {
	printf("queue\n");
      } else {
	printf("priority queue\n");
      }
    }
  }
  return 0;

}
