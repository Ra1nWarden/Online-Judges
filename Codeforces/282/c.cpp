#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int main() {
  string line;
  getline(cin, line);
  int v[line.length()];
  vector<int> slots;
  int prev = 0;
  for(int i = 0; i < line.length(); i++) {
    if(line[i] == '(') {
      prev++;
    }
    if(line[i] == ')' || line[i] == '#') {
      prev--;
    }
    if(line[i] == '#')
      slots.push_back(i);
    if(prev < 0) {
      cout << -1 << endl;
      return 0;
    }
    v[i] = prev;
  }
  if(v[line.length() - 1] < 0)
    cout << -1 << endl;
  else {
    int result[slots.size()];
    for(int i = 0; i < slots.size(); i++)
      result[i]  = 1;
    int subtracted = 0;
    for(int i = 0; i < slots.size(); i++) {
      int nexti = slots[i];
      int minv = INF;
      for(int j = nexti; j < line.length(); j++)
	minv = min(minv , v[j] - subtracted);
      subtracted += minv;
      result[i] += minv;
      if(v[line.length() - 1] - subtracted == 0)
	break;
    }
    if(v[line.length() - 1] - subtracted != 0)
      cout << -1 << endl;
    else {
      for(int i= 0; i < slots.size(); i++)
	cout << result[i] << endl;
    }
  }
  return 0;
}
