#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> v;
  int result = 0;
  for(int i= 0; i < n; i++) {
    int x;
    cin >> x;
    v.insert(x);
  }
  for(set<int>::iterator xitr = v.begin(); xitr != v.end(); xitr++) {
    int x = *xitr;
    if(x <= result)
      continue;
    else {
      for(set<int>::iterator itr = lower_bound(v.begin(), v.end(), result); *itr != x; itr++) {
	int next = *itr;
	int newval = x % next;
	if(newval > result) {
	  result = newval;
	}
      }
    }
  }
  cout << result << endl;
  return 0;
}
