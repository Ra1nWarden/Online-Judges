#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  map<string, int> si;
  map<int, string> is;
  string parent, child;
  int v[300];
  for(int i = 0; i < 300; i++)
    v[i] = i;
  int index = 0;
  while(cin >> child >> parent) {
    if(child == "no.child")
      break;
    if(si.count(parent) == 0) {
      si[parent] = index++;
      is[index-1] = parent;
    }
    if(si.count(child) == 0) {
      si[child] = index++;
      is[index-1] = child;
    }
    //cout << "setting v : " << child << " has parent " << parent << endl;
    v[si[child]] = si[parent];
  }
  string querys, querye;
  while(cin >> querye >> querys) {
    if(si.count(querye) == 0 || si.count(querys) == 0) {
      cout << "no relation" << endl;
      continue;
    }
    int start = si[querys];
    int end = si[querye];
    vector<int> starta;
    int startc = start;
    bool determined = false;
    while(v[startc] != startc) {
      int next = v[startc];
      if(next == end) {
	determined = true;
	break;
      }
      starta.push_back(next);
      startc = v[startc];
    }
    if(determined) {
      if(starta.size() == 0)
	cout << "parent" << endl;
      else {
	for(int i = 0; i < starta.size() - 1; i++)
	  cout << "great ";
	cout << "grand parent" << endl;
      }
      continue;
    }
    vector<int> enda;
    int endc = end;
    int match = -2;
    while(v[endc] != endc) {
      int next = v[endc];
      if(next == start) {
	determined = true;
	match = -1;
	break;
      } else {
	vector<int>::iterator listcheck = find(starta.begin(), starta.end(), next);
	if (listcheck != starta.end()) {
	  determined = true;
	  match = *listcheck;
	  break;
	}
	else
	  enda.push_back(next);
      }
      endc = v[endc];
    }

    // cout << "start is " << querys << endl;
    // for(int i= 0; i < starta.size(); i++)
    //   cout << is[starta[i]] << " ";
    // cout << endl;
    // cout << "end is " << querye << endl;
    // for(int i= 0; i < enda.size(); i++)
    //   cout << is[enda[i]] << " ";
    // cout << endl;


    if(determined) {
      if(match == -1) {
	if(enda.size() == 0)
	  cout << "child" << endl;
	else {
	  for(int i= 0; i < enda.size() - 1; i++) {
	    cout << "great ";
	  }
	  cout << "grand child" << endl;
	}
      } else {
	// sibling or cousin
	int x = enda.size();
	int y = find(starta.begin(), starta.end(), match) - starta.begin();
	int k = min(x, y);
	int j = abs(x - y);
	if(k == 0 && j == 0)
	  cout << "sibling" << endl;
	else {
	  if(j != 0)
	    cout << k << " cousin removed " << j << endl; 
	  else
	    cout << k << " cousin" << endl;
	}
      }
    }
    else
      cout << "no relation" << endl;
  }
  return 0;
}
