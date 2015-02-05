#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  map<string, char> morse;
  morse[".-"] = 'A';
  morse["-..."] = 'B';
  morse["-.-."] = 'C';
  morse["-.."] = 'D';
  morse["."] = 'E';
  morse["..-."] = 'F';
  morse["--."] = 'G';
  morse["...."] = 'H';
  morse[".."] = 'I';
  morse[".---"] = 'J';
  morse["-.-"] = 'K';
  morse[".-.."] = 'L';
  morse["--"] = 'M';
  morse["-."] = 'N';
  morse["---"] = 'O';
  morse[".--."] = 'P';
  morse["--.-"] = 'Q';
  morse[".-."] = 'R';
  morse["..."] = 'S';
  morse["-"] = 'T';
  morse["..-"] = 'U';
  morse["...-"] = 'V';
  morse[".--"] = 'W';
  morse["-..-"] = 'X';
  morse["-.--"] = 'Y';
  morse["--.."] = 'Z';
  morse["-----"] = '0';
  morse[".----"] = '1';
  morse["..---"] = '2';
  morse["...--"] = '3';
  morse["....-"] = '4';
  morse["....."] = '5';
  morse["-...."] = '6';
  morse["--..."] = '7';
  morse["---.."] = '8';
  morse["----."] = '9';
  morse[".-.-.-"] = '.';
  morse["--..--"] = ',';
  morse["..--.."] = '?';
  morse[".----."] = '\'';
  morse["-.-.--"] = '!';
  morse["-..-."] = '/';
  morse["-.--."] = '(';
  morse["-.--.-"] = ')';
  morse[".-..."] = '&';
  morse["---..."] = ':';
  morse["-.-.-."] = ';';
  morse["-...-"] = '=';
  morse[".-.-."] = '+';
  morse["-....-"] = '-';
  morse["..--.-"] = '_';
  morse[".-..-."] = '\"';
  morse[".--.-."] = '@';
  int cases;
  cin >> cases >> ws;
  for(int i = 0; i < cases; i++) {
    if (i != 0)
      cout << endl;
    cout << "Message #" << i+1 << endl;
    string line;
    getline(cin, line);
    string output = "";
    bool inputstatus = false;
    for(int i = 0; i < line.length(); i++) {
      if(line[i] == ' ') {
	if(inputstatus) {
	  cout << morse[output];
	  output = "";
	  inputstatus = false;
	}
	else {
	  cout << ' ';
	}
      }
      else {
	inputstatus = true;
	output += line[i];
      }
    }
    if (output != "")
      cout << morse[output];
    cout << endl;
  }
  return 0;
}
