#include <iostream>

using namespace std;

string l(string a, string b) {
  //cout << "l operation" << endl;
  //cout << b << endl;
  string result =  b + "V";
  //cout << result << endl;
  return result;
}

string r(string a, string b) {
  //cout << "r operation" << endl;
  //cout << b << endl;
  string result =  "V"+b.substr(0, b.length() - 1);
  //cout << result << endl;
  return result;
}

int strtoi(string s) {
  int result = 0;
  int base = 1;
  for(int i = s.length() - 1; i >= 0; i--) {
    int mult = 0;
    switch(s[i]) {
    case 'V':
      mult = 0;
      break;
    case 'U':
      mult = 1;
      break;
    case 'C':
      mult = 2;
      break;
    case 'D':
      mult = 3;
      break;
    }
    result += (base * mult);
    base *= 4;
  }
  //cout << s << "->" << result << endl;
  return result;
}

string itos(int n) {
  string result = "";
  string convert = "VUCD";
  //cout << n;
  while(n != 0) {
    result = convert[n % 4] + result;
    n /= 4;
  }
  //cout << "->" << result << endl;
  return result;
}

string sum(string a, string b) {
  int num1 = strtoi(a);
  int num2 = strtoi(b);
  int sum = num1 + num2;
  //cout << "sum is " << sum << endl;
  string result = itos(sum);
  //cout << "sum operation" << endl;
  //cout << a << ", " << b << endl;
  //cout << result << endl;
  return result;
}

int main() {
  cout << "COWCULATIONS OUTPUT" << endl;
  int n; 
  cin >> n >> ws; 
  string line; 
  while(n--) { 
      string num1;
      getline(cin, num1);
      string num2;
      getline(cin, num2);
      for(int i= 0; i < 3; i++) {
	getline(cin, line);
	if(line == "A")
	  num2 = sum(num1, num2);
	if(line == "L")    
	  num2 = l(num1, num2);
	if(line == "R")
	  num2 = r(num1, num2);
      }
      while(num2.length() != 8)
	num2 = "V" + num2;
 
      string result;
      getline(cin, result);
      
      //cout << num2 << endl;
      //cout << result << endl;
      cout << (result == num2 ? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
