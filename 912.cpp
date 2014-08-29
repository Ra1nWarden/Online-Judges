#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    istringstream iss(line.c_str());
    int length;
    iss >> length;
    vector<string> first;
    vector<string> second;
    for (int i = 0; i < length; i++) {
      getline(cin, line);
      first.push_back(line);
    }
    for (int i = 0; i < length; i++) {
      getline(cin, line);
      second.push_back(line);
    }
    map<int, int> unionFindMap;
    map<int, char> decodeMap;
    bool possible = true;
    for (int i = 0; i < length; i++) {
      if (first[i] != second[i]) {
	char firstChar = first[i][0];
	char secondChar = second[i][0];
	bool firstAlph = firstChar >= 'A' && firstChar <= 'D';
	bool secondAlph = secondChar >= 'A' && secondChar <= 'D';
	if (firstAlph && secondAlph) {
	  possible = (firstChar == secondChar);
	}
	else if (firstAlph && !secondAlph) {
	  int mutantNumber;
	  istringstream iss(second[i].c_str());
	  iss >> mutantNumber;
	  if (decodeMap.count(mutantNumber) == 0) {
	    decodeMap[mutantNumber] = firstChar;
	  }
	  else {
	    possbile = (firstChar == decodeMap[mutantNumber]);
	  }
	  if (unionFindMap.count(mutantNumber) == 0)
	    unionFindMap[mutantNumber] = mutantNumber;
	}
	else if (!firstAlph && secondAlph) {
	  int mutantNumber;
	  istringstream iss(first[i].c_str());
	  iss >> mutantNumber;
	  if (decodeMap.count(mutantNumber) == 0) {
	    decodeMap[mutantNumber] = secondChar;
	  }
	  else {
	    possbile = (secondChar == decodeMap[mutantNumber]);
	  }
	  if (unionFindMap.count(mutantNumber) == 0)
	    unionFindMap[mutantNumber] = mutantNumber;
	}
	else {
	  int mutantNumber1, mutantNumber2;
	  istringstream iss1(first[i].c_str());
	  iss1 >> mutantNumber1;
	  istringstream iss2(second[i].c_str());
	  iss2 >> mutantNumber2;
	  combine(mutantNumber1, mutantNumber2, unionFindMap);
	}
      }
      if (!possible)
	break;
    }
    if (possible) {
      bool furtherCheck = true;
      for(map<int, int>::iterator itr = unionFindMap.begin(); itr != unionFindMap.end(); itr++) {
	int selfNumber = itr->first;
	unionFindMap[selfNumber] = findSet(selfNumber, unionFindMap);
      }
      
    }
    else {
      cout << "NO" << endl;
    }
    if (!getline(cin, line))
      break;
  }
  return 0;
}
