#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int nodes;
    cin >> nodes >> ws;
    string line;
    int minCount = -1;
    vector<int> indices;
    for (int j = 0; j < nodes; j++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      int path;
      int count = 0;
      while (iss >> path)
	count++;
      if (minCount == -1) {
	minCount = count;
	indices.push_back(j + 1);
	continue;
      }
      if (count < minCount) {
	indices.clear();
	indices.push_back(j + 1);
	minCount = count;
	continue;
      }
      if (count == minCount) {
	indices.push_back(j + 1);
	continue;
      }
    }
    for (int j = 0; j < indices.size(); j++) {
      if (j != 0)
	cout << ' ';
      cout << indices[j];
    }
    cout << endl;
  }
  return 0;
}
