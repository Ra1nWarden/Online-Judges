#include <iostream>
#include <map>

using namespace std;

int main() {
  int q;
  cin >> q;
  string line;
  getline(cin, line);
  map<string, string> forward;
  map<string, string> backward;
  for(int i = 0; i < q; i++) {
    string olds, news;
    cin >> olds >> news;
    if(backward.count(olds) == 0) {
      forward[olds] = news;
      backward[news] = olds;
    } else {
      forward[backward[olds]] = news;
      backward[news] = backward[olds];
    }
  }
  cout << forward.size() << endl;
  for(map<string, string>::iterator itr = forward.begin(); itr != forward.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }
  return 0;
}
