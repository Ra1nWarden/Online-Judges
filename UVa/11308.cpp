#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

struct RecipeCost {
  string name;
  int cost;
  RecipeCost(string s, int n) : name(s), cost(n) {};
  bool operator<(const RecipeCost& second) const {
    if (cost < second.cost)
      return true;
    else if (cost == second.cost)
      return name < second.name;
    else
      return false;
  };
};

int main() {
  int cases;
  cin >> cases >> ws;
  for(int i = 0; i < cases; i++) {
    string binder;
    getline(cin, binder);
    int ingredients, recipies, budget;
    cin >> ingredients >> recipies >> budget >> ws;
    map<string, int> ingredientsCosts;
    for(int j = 0; j < ingredients; j++) {
      string line;
      getline(cin, line);
      istringstream iss(line.c_str());
      string ingrename;
      int ingrecost;
      iss >> ingrename >> ingrecost;
      ingredientsCosts[ingrename] = ingrecost;
    }
    vector<RecipeCost> totalcostVec;
    for(int k = 0; k < recipies; k++) {
      string recipname;
      getline(cin, recipname);
      int requirements;
      cin >> requirements >> ws;
      int totalcost = 0;
      for(int l = 0; l < requirements; l++) {
	string line;
	getline(cin, line);
	istringstream iss(line.c_str());
	string ingrename;
	int amount;
	iss >> ingrename >> amount;
	totalcost += (amount * ingredientsCosts[ingrename]);
      }
      RecipeCost oneCost(recipname, totalcost);
      totalcostVec.push_back(oneCost);
    }
    sort(totalcostVec.begin(), totalcostVec.end());
    for(int k = 0; k < binder.length(); k++)
      cout << (char) toupper(binder[k]);
    cout << endl;
    for(int k = 0; k < totalcostVec.size(); k++) {
      if(totalcostVec[k].cost > budget) {
	if (k == 0)
	  cout << "Too expensive!" << endl;
	break;
      }
      cout << totalcostVec[k].name << endl;
    }
    cout << endl;
  }
  return 0;
}
