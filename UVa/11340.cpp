#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int getCostLine(string& line, map<char, int>& priceMap) {
  int result = 0;
  for(int i = 0; i < line.length(); i++)
    result += priceMap[line[i]];
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int keyCount;
    cin >> keyCount;
    map<char, int> priceMap;
    for(int j = 0; j < keyCount; j++) {
      char keyChar;
      int priceChar;
      cin >> keyChar >> priceChar;
      priceMap[keyChar] = priceChar;
    }
    int msgLength;
    cin >> msgLength >> ws;
    int totalCost = 0;
    for(int j = 0 ; j < msgLength; j++) {
      string line;
      getline(cin ,line);
      totalCost += getCostLine(line, priceMap);
    }
    double returnResult = ((double) totalCost) / 100;
    printf("%.2f$\n", returnResult);
  }
  return 0;
}
