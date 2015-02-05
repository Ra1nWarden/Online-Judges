#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool DEBUG = false;

struct Choice {
  Choice(string n, int x) : name(n), cost(x) {};
  string name;
  int cost;
  bool operator<(const Choice& another) const {
    if (cost != another.cost)
      return cost < another.cost;
    else
      return name < another.name;
  };
};

int findTotalCost(int n, int m, int a, int b, int cost) {
  if(n == m)
    return cost;
  else {
    if(n / 2 < m) {
      return cost + (n-m)*a;
    } else {
      // n/2 >= m
      int bcost = b; 
      int acost = (n - n/2) * a;
      return bcost < acost ? findTotalCost(n/2, m, a, b, cost + bcost) : findTotalCost(n/2, m, a, b, cost + acost);
    }
  }
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int n, m, l;
    cin >> n >> m >> l >> ws;
    vector<Choice> choices;
    for(int j = 0; j < l; j++) {
      string line;
      getline(cin, line);
      istringstream iss(line.c_str());
      string agencyName;
      string rest;
      getline(iss, agencyName, ':');
      getline(iss, rest);
      istringstream iss2(rest.c_str());
      string astr, bstr;
      getline(iss2, astr, ',');
      int a = atoi(astr.c_str());
      getline(iss2, bstr);
      int b = atoi(bstr.c_str());
      int result = findTotalCost(n, m, a, b, 0);
      choices.push_back(Choice(agencyName, result));
    }
    sort(choices.begin(), choices.end());
    cout << "Case " << i+1 << endl;
    for(int j = 0; j < choices.size(); j++)
      cout << choices[j].name << " " << choices[j].cost << endl;
  }
  return 0;
}
