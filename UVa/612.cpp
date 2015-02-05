#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Sequence {
  string content;
  int inverses;
  Sequence(string str) {
    content = str;
    int result = 0;
    for(int i = 0; i < str.length()-1; i++) {
      char first = str[i];
      for(int j = i+1; j < str.length(); j++) {
	char second = str[j];
	if (first > second)
	  result++;
      }
    }
    inverses = result;
  };
  bool operator<(const Sequence& sec) const {
    return inverses < sec.inverses;
  };
};

int main() {
  int cases;
  cin >> cases >> ws;
  string line;
  for(int i = 0; i < cases; i++) {
    if (i != 0)
      cout << endl;
    int length, counts;
    cin >> length >> counts >> ws;
    vector<Sequence> onecase;
    for(int j = 0; j < counts; j++) {
      getline(cin, line);
      onecase.push_back(Sequence(line));
    }
    stable_sort(onecase.begin(), onecase.end());
    for(int j = 0; j < counts; j++)
      cout << onecase[j].content << endl;
    if (i != cases - 1)
      getline(cin, line);
  }
  return 0;
}
