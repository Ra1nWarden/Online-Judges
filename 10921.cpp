#include <iostream>
#include <map>

using namespace std;

string translate(string& orig, map<char, string>& converts) {
  string result = "";
  for(int i = 0; i < orig.length(); i++) {
    char each = orig[i];
    if(converts.count(each) <= 0)
      result += each;
    else
      result += converts[each];
  }
  return result;
} 

int main() {
  string line;
  map<char, string> myMap;
  myMap['A'] = "2";
  myMap['B'] = "2";
  myMap['C'] = "2";
  myMap['D'] = "3";
  myMap['E'] = "3";
  myMap['F'] = "3";
  myMap['G'] = "4";
  myMap['H'] = "4";
  myMap['I'] = "4";
  myMap['J'] = "5";
  myMap['K'] = "5";
  myMap['L'] = "5";
  myMap['M'] = "6";
  myMap['N'] = "6";
  myMap['O'] = "6";
  myMap['P'] = "7";
  myMap['Q'] = "7";
  myMap['R'] = "7";
  myMap['S'] = "7";
  myMap['T'] = "8";
  myMap['U'] = "8";
  myMap['V'] = "8";
  myMap['W'] = "9";
  myMap['X'] = "9";
  myMap['Y'] = "9";
  myMap['Z'] = "9";
  while(true) {
    getline(cin, line);
    if(!cin)
      break;
    string converted = translate(line, myMap);
    cout << converted << endl;
  }
  return 0;
}
