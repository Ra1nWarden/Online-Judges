#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

string divideByTwo(string num) {
  ostringstream oss;
  bool overflow = false;
  for(int i= 0; i < num.length(); i++) {
    int dig = atoi(num.substr(i, 1).c_str());
    if(overflow)
      dig = 10 + dig;
    if(dig == 1) {
      if(i != 0) 
	oss << 0;
      overflow = true;
    } else {
      oss << dig / 2;
      overflow = (dig % 2 == 1);
    }
  }
  return oss.str();
}

bool odd(string num) {
  int lastDig = atoi(num.substr(num.length() - 1, 1).c_str());
  return lastDig % 2 == 1;
}

string subtract(string num) {
  int lastDig = atoi(num.substr(num.length() - 1, 1).c_str());
  if(lastDig == 0) {
    string result = subtract(num.substr(0, num.length() - 1)) + "9";
    if(result[0] == '0') {
      return result.substr(1);
    } else
      return result;
  } else {
    ostringstream oss;
    oss << (num.substr(0, num.length() - 1).c_str());
    oss << (lastDig - 1);
    return oss.str();
  }
}

int main() {
  ifstream ifs("china.in");
  ofstream ofs("china.out");
  string num;
  ifs >> num;
  if(odd(num)) {
    string subtracted = subtract(num);
    //cout << subtracted << endl;
    ofs << divideByTwo(subtracted) << endl;
  } else {
    string half = divideByTwo(num);
    //cout << half << endl;
    if(odd(half))
      ofs << subtract(subtract(half)) << endl;
    else
      ofs << subtract(half) << endl;
  }
  ifs.close();
  ofs.close();
  return 0;
}
