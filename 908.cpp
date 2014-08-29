#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Line {
  long a, b, cost;
  Line(long x, long y, long z) : a(x), b(y), cost(z) {};
  bool operator<(const Line& another) const {
    return cost > another.cost; 
  };
};

int main() {
  long computers;
  bool firstCase = true;
  while(cin >> computers) {
    if (!firstCase)
      cout << endl;
    firstCase = false;
    long origcost = 0;
    for(int i = 0; i < computers - 1; i++) {
      long a, b, cost;
      cin >> a >> b >> cost;
      origcost += cost;
    }
    priority_queue<Line> options;
    for(int j = 0; j < 2; j++) {
      long additional;
      cin >> additional;
      for(int i = 0; i < additional; i++) {
	long a, b, cost;
	cin >> a >> b >> cost;
	Line enter(a, b, cost);
	options.push(enter);
      }
    }
    long newresult = 0;
    Line first = options.top();
    options.pop();
    newresult += first.cost;
    set<long> connectedNodes;
    connectedNodes.insert(first.a);
    connectedNodes.insert(first.b);
    map<long, set<long> > adjnodes;
    adjnodes[first.a] = connectedNodes;
    adjnodes[first.b] = connectedNodes;
    for(long j = 1; j < computers - 1; j++) {
      while(true) {
	Line next = options.top();
	options.pop();
	bool apresent = adjnodes.count(next.a);
	bool bpresent = adjnodes.count(next.b);
	if(!apresent) {
	  set<long> dummy;
	  dummy.insert(next.a);
	  adjnodes[next.a] = dummy;
	}
	if(!bpresent) {
	  set<long> dummy;
	  dummy.insert(next.b);
	  adjnodes[next.b] = dummy;
	}
	set<long> firstNodes = adjnodes[next.a];
	set<long> secondNodes = adjnodes[next.b];
	long allocsize = firstNodes.size() < secondNodes.size() ? firstNodes.size() : secondNodes.size();
	vector<long> intersection(allocsize);
	vector<long>::iterator itr = set_intersection(firstNodes.begin(), firstNodes.end(), secondNodes.begin(), secondNodes.end(), intersection.begin());
	intersection.resize(itr - intersection.begin());
	if (intersection.empty()) {
	  firstNodes.insert(next.b);
	  secondNodes.insert(next.a);
	  adjnodes[next.a] = firstNodes;
	  adjnodes[next.b] = secondNodes;
	  newresult += next.cost;
	  break;
	}
      }
    }
    cout << origcost << endl << newresult << endl;
  }
  return 0;
}
