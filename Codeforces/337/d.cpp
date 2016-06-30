#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Line {
  int idx, start, end;
  Line() {}
  Line(int i, int s, int e) : idx(i), start(s), end(e) {}
  bool operator<(const Line& rhs) const {
    if(idx != rhs.idx)
      return idx < rhs.idx;
    if(start != rhs.start)
      return start < rhs.start;
    return end < rhs.end;
  }
};

enum EventType {
  Begin, End, Intersect
};

struct Event {
  EventType t;
  int coord, idx;
  Event(EventType tt, int c, int i) : t(tt), coord(c), idx(i) {}
  bool operator<(const Event& rhs) const {
    if(coord != rhs.coord)
      return coord < rhs.coord;
    if(rhs.t == EventType.Intersect) {
      return t != EventType.Intersect;
    } else {
      return false;
    }
  }
};
const int maxn = 100000;
Line vertical[maxn+1];
Line horizontal[maxn+1];
int vi, hi, n;

void merge(Line* lines, int& len) {
  int ll = 0;
  for(int i = 1; i < len; i++) {
    if(lines[i].idx == lines[ll].idx && lines[i].start >= lines[ll].start && lines[i].start <= lines[ll].end) {
      lines[ll].end = max(lines[ll].end, lines[i].end);
    } else {
      lines[++ll].idx = lines[i].idx;
      lines[ll].start = lines[i].start;
      lines[ll].end = lines[i].end;
    }
  }
  len = ll + 1;
}

int main() {
  vi = hi = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if(x1 == x2) {
      vertical[vi++] = Line(x1, min(y1, y2), max(y1, y2));
    }
    else if(y1 == y2) {
      horizontal[hi++] = Line(y1, min(x1, x2), max(x1, x2));
    }
  }
  sort(vertical, vertical + vi);
  sort(horizontal, horizontal + hi);
  merge(vertical, vi);
  merge(horizontal, hi);
  vector<Event> events;
  for(int i = 0; i < hi; i++) {
    events.push_back(Event(EventType.Begin, horizontal[i].start, i));
    events.push_back(Event(EventType.End, horizontal[i].end, i));
  }
  for(int i = 0; i < vi; i++) {
    events.push_back(Event(EventType.Intersect, vertical[i].idx, i));
  }
  sort(events.begin(), events.end());
  return 0;
}
