#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct bead {
  int a, b;
  bead(int a, int b):a(a),b(b) {};
  bool contain(int x) {
    if(a == x)
      return true;
    if(b == x) {
      int temp = a;
      a = b;
      b = temp;
      return true;
    }
    return false;
  };
};

vector<bead*> result;

void testItem(vector<int>& beads, int a) {
  if(count(beads.begin(), beads.end(), a) == 0)
    beads.push_back(a);
  else
    beads.erase(find(beads.begin(), beads.end(), a));
}

bool dfs(vector<bead*>& beadsleft, vector<bead*>& beadsconnected) {
  if(beadsconnected.size() > 1)
    if(beadsconnected[1]->b == 47)
      cout << "Right track!" << endl;
  int nextmatch = beadsconnected[beadsconnected.size() - 1]->b;
  if(beadsleft.size() == 1) {
    if(beadsleft[0]->contain(nextmatch)) {
      result = beadsconnected;
      result.push_back(beadsleft[0]);
      return true;
    }
    else
      return false;
  }
  else {
    bool resultval = false;
    for(int i = 0; i < beadsleft.size(); i++) {
      bead* current = beadsleft[i];
      if(current->contain(nextmatch)) {
	vector<bead*> nextconnect(beadsconnected);
	vector<bead*> nextleft;
	nextconnect.push_back(current);
	for(int j = 0; j < beadsleft.size(); j++) {
	  if(j == i)
	    continue;
	  nextleft.push_back(beadsleft[j]);
	}
	resultval = dfs(nextleft, nextconnect);
	if(resultval)
	  break;
      }
    }
    return resultval;
  }
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    if(i != 0)
      cout << endl;
    int bc;
    cin >> bc;
    vector<bead*> beads;
    vector<int> testcount;
    for(int j= 0; j < bc; j++) {
      int x, y;
      cin >> x >> y;
      testItem(testcount, x);
      testItem(testcount, y);
      bead* newbead = new bead(x, y);
      beads.push_back(newbead);
    }
    result.clear();
    if(testcount.size() == 0){
      vector<bead*> connected;
      vector<bead*> left(beads);
      connected.push_back(left[0]);
      left.erase(left.begin());
      bool resultbool = dfs(left, connected);
      if(resultbool) {
	cout << "Case #" << i+1 << endl;
	for(int j= 0; j < result.size(); j++)
	  cout << result[j]->a << " " << result[j]->b << endl;
      }
      else {
	cout << "Case #" << i+1 << endl;
	cout << "some beads may be lost" << endl;
      }
    }
    else {
      cout << "Case #" << i+1 << endl;
      cout << "some beads may be lost" << endl;
    }
  }
  return 0;
}
