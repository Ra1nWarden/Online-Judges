#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

string generateCode(int digit, char symbol1, char symbol5, char symbol10) {
  string result = "";
  if (digit < 4) {
    for(int i = 0; i < digit; i++)
      result += symbol1;
  }
  else if (digit == 4) {
    result += symbol1;
    result += symbol5;
  }
  else if (digit == 5)
    result += symbol5;
  else if (digit < 9) {
    result += symbol5;
    for(int i = 0; i < digit -5; i++)
      result += symbol1;
  }
  else {
    result += symbol1;
    result += symbol10;
  }
  return result;
}

int main() {
  map<char, int> valueMap;
  valueMap['I'] = 1;
  valueMap['V'] = 5;
  valueMap['X'] = 10;
  valueMap['L'] = 50;
  valueMap['C'] = 100;
  valueMap['D'] = 500;
  valueMap['M'] = 1000;
  string line;
  while(true) {
    getline(cin, line);
    if(!cin)
      break;
    if(line[0] >= '1' && line[0] <= '9') {
      int number = atoi(line.c_str());
      int thousand, hundred, ten, one;
      thousand = number / 1000;
      hundred = (number % 1000) / 100;
      ten = (number % 100) / 10;
      one = number % 10;
      string output = "";
      for(int i = 0; i < thousand; i++)
	output += 'M';
      output += generateCode(hundred, 'C', 'D', 'M');
      output += generateCode(ten, 'X', 'L', 'C');
      output += generateCode(one, 'I', 'V', 'X');
      cout << output << endl;
    }
    else {
      int result = 0;
      for(int i = 0; i < line.length(); i++) {
	if(i != line.length() - 1) {
	  int first = valueMap[line[i]];
	  int second = valueMap[line[i+1]];
	  if(first < second)
	    result -= first;
	  else
	    result += first;
	}
	else {
	  result += valueMap[line[i]];
	}
      }
      cout << result << endl;
    }
  }
  return 0;
}
