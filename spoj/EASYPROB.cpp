#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

string generate(int num) {
  if(num == 0) {
    return "0";
  }
  vector<int> powers;
  int mask = 1;
  int pos = 0;
  while(mask <= num) {
    if(mask & num) {
      powers.push_back(pos);
    }
    pos++;
    mask <<= 1;
  }
  stringstream ss;
  for(int i = 0; i < powers.size(); i++) {
    if(i) {
      ss << '+';
    }
    ss << "2(" << generate(powers[i]) << ")";
  }
  string ret = ss.str();
  return ret;
}

int main() {
  int v[] = {137, 1315, 73, 136, 255, 1384, 16385};
  for(int i = 0; i < 7; i++)
    printf("%d=%s\n",v[i], generate(v[i]).c_str());
  return 0;
}
