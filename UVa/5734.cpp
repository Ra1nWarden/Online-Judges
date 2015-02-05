#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int getDigit(int a, int b) {
  int result = b - a;
  if(result < 0)
    result += 8;
  result %= 8;
  return result;
}

vector<int> getCode(string& line) {
  vector<int> result;
  vector<int> raw;
  for(int i = 0; i < line.length(); i++) 
    raw.push_back(atoi(line.substr(i, 1).c_str()));
  for(int i = 0; i < raw.size(); i++) {
    if(i == raw.size() - 1) {
      result.push_back(getDigit(raw[i], raw[0]));
    }
    else
      result.push_back(getDigit(raw[i], raw[i+1]));
  }
  return result;
}

int getMinIndex(vector<int>& code) {
  vector<int> minIndex;
  int minval = 10;
  for(vector<int>::iterator itr = code.begin(); itr != code.end(); ++itr) {
    if(*itr < minval)
      minval = *itr;
    if(minval == 0)
      break;
  }
  for(int i = 0;i < code.size(); i++) {
    if(code[i] == minval)
      minIndex.push_back(i);
  }
  int cycles = 0;
  while(minIndex.size() != 1) {
    vector<int> nextMinIndex;
    int minval = 10;
    for(int i = 0; i < minIndex.size(); i++) {
      int nextIndex = minIndex[i] + 1;
      nextIndex %= code.size();
      int nextnumber = code[nextIndex];
      if(nextnumber < minval)
	minval = nextnumber;
      if(minval == 0)
	break;
    }
    for(int i = 0; i < minIndex.size(); i++) {
      int nextIndex = minIndex[i] + 1;
      nextIndex %= code.size();
      int nextNum = code[nextIndex];
      if(nextNum == minval)
	nextMinIndex.push_back(minIndex[i]);
    }
    minIndex = nextMinIndex;
    cycles++;
    if(cycles > code.size())
      break;
  }
  return minIndex[0];
}

int main() {
  while(!cin.eof()) {
    string line;
    getline(cin, line);
    vector<int> code = getCode(line);
    int minIndex = getMinIndex(code);
    for(int i = 0; i < code.size(); i++) {
      minIndex %= code.size();
      cout << code[minIndex];
      minIndex++;
    }
    cout << endl;
  }
  return 0;
}
