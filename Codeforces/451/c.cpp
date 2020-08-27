#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string> > phone_book;

bool check(string a, string b) {
  for(int i = 0; i < min(a.length(), b.length()); i++) {
    if(a[a.length() - 1 - i] != b[b.length() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int m;
  cin >> m;
  while(m--) {
    string name;
    cin >> ws >> name;
    int n;
    cin >> n;
    string number;
    while(n--) {
      cin >> number;
      if(phone_book.count(name)) {
	vector<string>& numbers = phone_book[name];
	int i;
	for(i = 0; i < numbers.size(); i++) {
	  if(check(numbers[i], number)) {
	    break;
	  }
	}
	if(i < numbers.size()) {
	  if(numbers[i].length() < number.length()) {
	    numbers[i] = number;
	  }
	} else {
	  numbers.push_back(number);
	}
      } else {
	phone_book[name].push_back(number);
      }
    }
  }
  cout << phone_book.size() << endl;
  for(auto each = phone_book.begin(); each != phone_book.end(); each++) {
    cout << each->first << " " << each->second.size();
    for(int i = 0; i < each->second.size(); i++) {
      cout << " " << each->second[i];
    }
    cout << endl;
  }
  return 0;
}
