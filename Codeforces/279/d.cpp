#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> cho;
typedef pair<cho, cho> chos;
typedef pair<chos, int> node;

bool ok(chos ch) {
  return ch.first.first * ch.first.second == ch.second.first * ch.second.second;
}

int main() {
  int64_t a, b, c, d;
  cin >> a >> b >> c >> d;
  node start = make_pair(make_pair(make_pair(a, b), make_pair(c, d)), 0);
  queue<node> q;
  bool success = false;
  q.push(start);
  while(!q.empty()) {
    node next = q.front();
    //cout << "front of queue:" << endl;
    //cout << next.first.first.first << " " << next.first.first.second << endl;
    //cout << next.first.second.first << " " << next.first.second.second << endl;
    q.pop();
    if(ok(next.first)) {
      cout << next.second << endl;
      cout << next.first.first.first << " " << next.first.first.second << endl;
      cout << next.first.second.first << " " << next.first.second.second << endl;
      success = true;
      break;
    }
    chos chocolate = next.first;
    int nextStep = next.second + 1;
    if(chocolate.first.first % 2 == 0) {
      chos newcho = chocolate;
      newcho.first.first /= 2;
      q.push(make_pair(newcho, nextStep));
    }
    if(chocolate.first.first % 3 == 0) {
      chos newcho = chocolate;
      newcho.first.first /= 3;
      newcho.first.first *= 2;
      q.push(make_pair(newcho, nextStep));
    }
   if(chocolate.first.second % 2 == 0) {
     chos newcho = chocolate;
     newcho.first.second /= 2;
     q.push(make_pair(newcho, nextStep));
    }
    if(chocolate.first.second % 3 == 0) {
      chos newcho = chocolate;
      newcho.first.second /= 3;
      newcho.first.second *= 2;
      q.push(make_pair(newcho, nextStep));
    }
    if(chocolate.second.first % 2 == 0) {
      chos newcho = chocolate;
      newcho.second.first /= 2;
      q.push(make_pair(newcho, nextStep));
    }
    if(chocolate.second.first % 3 == 0) {
      chos newcho = chocolate;
      newcho.second.first /= 3;
      newcho.second.first *= 2;
      q.push(make_pair(newcho, nextStep));
    }
   if(chocolate.second.second % 2 == 0) {
     chos newcho = chocolate;
     newcho.second.second /= 2;
     q.push(make_pair(newcho, nextStep));
   }
    if(chocolate.second.second % 3 == 0) {
      chos newcho = chocolate;
      newcho.second.second /= 3;
      newcho.second.second *= 2;
      q.push(make_pair(newcho, nextStep));
    }
  }
  if(!success)
    cout << -1 << endl;
  return 0;
}
