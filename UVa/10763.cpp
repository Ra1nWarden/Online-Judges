#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool DEBUG = false;

struct Fe {
  Fe(int a, int b) : start(a), end(b) {};
  int start, end;
  bool operator<(const Fe& another) const {
    if (start == another.start)
      return end < another.end;
    else
      return start < another.start;
  }
  bool operator==(const Fe& another) const {
    return start == another.start && end == another.end;
  }
};

int main() {
  int count;
  while(cin >> count && count) {
    int result = 0;
    map<Fe, int> femap;
    for(int i = 0; i < count; i++) {
      int a, b;
      cin >> a >> b;
      Fe each(a, b);
      Fe check(b, a);
      if(DEBUG)
	cout << "femap[check] for a " << b << " b " << a  << " is " << femap[check] << endl;
      if (femap.count(check) == 0 || femap[check] == 0) {
	if (femap.count(each) == 0)
	  femap[each] = 0;
	femap[each] = femap[each] + 1;
	if(DEBUG)
	  cout << "++ for a " << a << " b " << b << endl;
	result++;
      } else {
	result--;
	if(DEBUG)
	  cout << "-- for a " << a << " b " << b << endl;
	femap[check] = femap[check] - 1;
      }
    }
    cout << (result == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
