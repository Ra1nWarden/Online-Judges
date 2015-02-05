#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void printH(int numcount, vector<int> &listofno, map<int, int>& patternmap, int length) {
  for(int i = 0; i < numcount; i++) {
    if(i > 0)
      cout << " ";
    cout << " ";
    int currentnum = listofno[i];
    int pattern = patternmap[currentnum];
    if(pattern == 1) {
      for(int j = 0; j < length; j++)
	cout << "-";
    }
    else {
      for(int j = 0; j < length; j++)
	cout << " ";
    }
    cout << " ";
  }
  cout << endl;
}

void printV(int numcount, vector<int> &listofno, map<int, int>& patternmap, int length) {
   for(int i = 0; i < length; i++) {
    for(int j = 0; j < numcount; j++) {
      if(j > 0)
	cout << " ";
      int currentnum = listofno[j];
      int pattern = patternmap[currentnum];
      switch(pattern) {
      case 0:
	for(int k = 0; k < length + 2; k++)
	  cout << " ";
	break;
      case 1:
	for(int k = 0; k < length + 1; k++)
	  cout << " ";
	cout << "|";
	break;
      case 2:
	cout << "|";
	for(int k = 0; k < length+1; k++)
	  cout << " ";
	break;
      case 3:
	cout << "|";
	for(int k = 0; k < length; k++)
	  cout << " ";
	cout << "|";
	break;
      }
    }
    cout << endl;
  }
}

int main() {
  map<int, int> firstH;
  firstH[0] = 1;
  firstH[1] = 0;
  firstH[2] = 1;
  firstH[3] = 1;
  firstH[4] = 0;
  firstH[5] = 1;
  firstH[6] = 1;
  firstH[7] = 1;
  firstH[8] = 1;
  firstH[9] = 1;
  map<int, int> secondV;
  secondV[0] = 3;
  secondV[1] = 1;
  secondV[2] = 1;
  secondV[3] = 1;
  secondV[4] = 3;
  secondV[5] = 2;
  secondV[6] = 2;
  secondV[7] = 1;
  secondV[8] = 3;
  secondV[9] = 3;
  map<int, int> thirdH;
  thirdH[0] = 0;
  thirdH[1] = 0;
  thirdH[2] = 1;
  thirdH[3] = 1;
  thirdH[4] = 1;
  thirdH[5] = 1;
  thirdH[6] = 1;
  thirdH[7] = 0;
  thirdH[8] = 1;
  thirdH[9] = 1;
  map<int, int> fourthV;
  fourthV[0] = 3;
  fourthV[1] = 1;
  fourthV[2] = 2;
  fourthV[3] = 1;
  fourthV[4] = 1;
  fourthV[5] = 1;
  fourthV[6] = 3;
  fourthV[7] = 1;
  fourthV[8] = 3;
  fourthV[9] = 1;
  map<int, int> fiveH;
  fiveH[0] = 1;
  fiveH[1] = 0;
  fiveH[2] = 1;
  fiveH[3] = 1;
  fiveH[4] = 0;
  fiveH[5] = 1;
  fiveH[6] = 1;
  fiveH[7] = 0;
  fiveH[8] = 1;
  fiveH[9] = 1;
  while(true) {
  string line;
  getline(cin, line);
  istringstream in (line.c_str());
  int length;
  in >> length;
  if(length == 0)
    break;
  string numbers;
  in >>  numbers;
  vector<int> listofno;
  for(int i = 0; i < numbers.length(); i++)
    listofno.push_back(atoi(numbers.substr(i, 1).c_str()));
  int numcount = listofno.size();
  printH(numcount, listofno, firstH, length);
  printV(numcount, listofno, secondV, length);
  printH(numcount, listofno, thirdH, length);
  printV(numcount, listofno, fourthV, length);
  printH(numcount, listofno, fiveH, length);
  cout << endl;
  }
  return 0;
}
