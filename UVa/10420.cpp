#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

int main() {
  int cases;
  cin >> cases >> ws;
  set<string> countries;
  map<string, int> countryCount;
  for(int i = 0; i < cases; i++) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string country;
    iss >> country;
    countries.insert(country);
    if (countryCount.count(country) == 0) {
      countryCount[country] = 1;
    }
    else {
      countryCount[country] = countryCount[country] + 1;
    }
  }
  for(set<string>::iterator itr = countries.begin(); itr != countries.end(); itr++) {
    cout << *itr << " " << countryCount[*itr] << endl;
  }
  return 0;
}
