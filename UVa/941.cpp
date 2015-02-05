#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

unsigned long long factorial(int number) {
  unsigned long long result = 1;
  for(int i = 1; i <= number; i++)
    result *= i;
  return result;
}

unsigned long long getTotalCount(vector<char>& chars) {
  set<char> uniqueChars;
  for(int i = 0; i < chars.size(); i++) {
    uniqueChars.insert(chars[i]);
  }
  unsigned long long result = factorial(chars.size());
  for(set<char>::iterator itr = uniqueChars.begin(); itr != uniqueChars.end(); itr++) {
    int count = 0;
    for(int i = 0; i < chars.size(); i++) {
      if (*itr == chars[i])
	count++;
    }
    if(count > 1)
      result /= (factorial(count));
  }
  return result;
}

string nthCombi(vector<char>& strleft, string& strformed, unsigned long long index) {
  set<char> uniqueChars;
  string result;
  if(strleft.size() == 0)
    return strformed;
  for(int i = 0; i < strleft.size(); i++)
    uniqueChars.insert(strleft[i]);
  for(set<char>::iterator itr = uniqueChars.begin(); itr != uniqueChars.end(); itr++) {
    vector<char> strCopy = strleft;
    strCopy.erase(find(strCopy.begin(), strCopy.end(), *itr));
    unsigned long long possibilities = getTotalCount(strCopy);
    if (possibilities < index)
      index -= possibilities;
    else {
      strformed += *itr;
      result = nthCombi(strCopy, strformed, index);
      break;
    }
  }
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    string line;
    cin >> ws;
    getline(cin, line);
    unsigned long long index;
    cin >> index;
    vector<char> characters;
    for(int i = 0; i < line.length(); i++)
      characters.push_back(line[i]);
    string empty = "";
    string result = nthCombi(characters, empty, index+1);
    cout << result << endl;
  }
  return 0;
}
