#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DEBUG = true;

struct Segment {
  Segment(int a, int b) : start(a), end(b) {};
  int start, end;
  bool operator<(const Segment& another) const {
    if (start != another.start) {
      return start < another.start;
    } else {
      return end < another.end;
    }
  };
};

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    if (i > 0)
      cout << endl;
    int m;
    cin >> m;
    int a, b;
    vector<Segment> segs;
    while(cin >> a >> b && (a || b)) {
      segs.push_back(Segment(a, b));
    }
    sort(segs.begin(), segs.end());
    Segment interval(0, m);
    vector<Segment> result;
    while(interval.end > interval.start) {
      int rightMost = 0;
      vector<Segment>::iterator selected = segs.end();
      for(vector<Segment>::iterator itr = segs.begin(); itr != segs.end(); itr++) {
	if (itr->start <= interval.start && itr->end > rightMost) {
	  selected = itr;
	  rightMost = itr->end;
	}
      }
      if(selected != segs.end()) {
	interval.start = selected->end;
	result.push_back(*selected);
      } else {
	break;
      }
    }
    if (interval.end > interval.start) {
      cout << 0 << endl;
    } else {
      sort(result.begin(), result.end());
      cout << result.size() << endl;
      for (int j = 0; j < result.size(); j++)
	cout << result[j].start << " " << result[j].end << endl;
    }
  }
  return 0;
}
