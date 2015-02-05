#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  int cases;
  string line;
  cin >> cases;
  getline(cin, line);
  for(int i = 0; i < cases; i++) {
    if (i != 0)
      cout << endl;
    getline(cin, line);
    getline(cin, line);
    istringstream iss(line.c_str());
    vector<int> indices;
    int eachindex;
    while(iss >> eachindex)
      indices.push_back(eachindex);
    getline(cin, line);
    vector<string> sorted(indices.size());
    istringstream issfloat(line.c_str());
    for(int j = 0; j < indices.size(); j++) {
      string eachfloat;
      issfloat >> eachfloat;
      sorted[indices[j] - 1] = eachfloat;
    }
    for(int j = 0; j < sorted.size(); j++)
      cout << sorted[j] << endl;
  }
  return 0;
}
