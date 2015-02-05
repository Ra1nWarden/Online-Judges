#include <iostream>
#include <vector>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string generateSoundCode(string& str, map<char, int>& encodeMap) {
  ostringstream oss;
  oss << str.substr(0, 1);
  int prev = encodeMap[str[0]];
  for(int i = 1; i < str.length(); i++) {
    int next = encodeMap[str[i]];
    if (next == prev)
      continue;
    else if (next == -1) {
      prev = -2;
    }
    else {
      oss << next;
    }
    if (oss.str().length() == 4)
      return oss.str();
    prev = next;
  }
  while(oss.str().length() < 4)
    oss << 0;
  return oss.str();
}

int main() {
  string line;
  map<char, int> encoding;
  encoding['A'] = -1;
  encoding['E'] = -1;
  encoding['I'] = -1;
  encoding['O'] = -1;
  encoding['U'] = -1;
  encoding['Y'] = -1;
  encoding['W'] = -1;
  encoding['H'] = -1;

  encoding['B'] = 1;
  encoding['P'] = 1;
  encoding['F'] = 1;
  encoding['V'] = 1;

  encoding['C'] = 2;
  encoding['S'] = 2;
  encoding['K'] = 2;
  encoding['G'] = 2;
  encoding['J'] = 2;
  encoding['Q'] = 2;
  encoding['X'] = 2;
  encoding['Z'] = 2;

  encoding['D'] = 3;
  encoding['T'] = 3;

  encoding['L'] = 4;
  
  encoding['M'] = 5;
  encoding['N'] = 5;

  encoding['R'] = 6;

  ostringstream outputss;
  while(outputss.str().length() != 9)
    outputss << " ";
  outputss << "NAME";
  while(outputss.str().length() != 34)
    outputss << " ";
  outputss << "SOUNDEX CODE";
  cout << outputss.str() << endl;
  while(true) {
    getline(cin, line);
    if(!cin)
      break;
    string soundCode = generateSoundCode(line, encoding);
    ostringstream liness;
    while(liness.str().length() != 9)
      liness << " ";
    liness << line;
    while(liness.str().length() != 34)
      liness << " ";
    liness << soundCode;
    cout << liness.str() << endl;
  }
  ostringstream finalline;
  while(finalline.str().length() != 19)
    finalline << " ";
  finalline << "END OF OUTPUT";
  cout << finalline.str() << endl;
  return 0;
}
