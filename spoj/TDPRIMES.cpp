#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int max_num = 100000000;
bool check[max_num+5];
int idx;
vector<int> v;

int main() {
  memset(check, false, sizeof check);
  for(int i = 2; i <= max_num; i++) {
    if(!check[i]) {
      v.push_back(i);
      if(v.size() % 100 == 1) {
	printf("%d\n", i);
      }
    }
    for(int j = 0; j < v.size(); j++) {
      if(i * 1LL * v[j] > max_num) {
	break;
      }
      check[i * v[j]] = true;
      if(i % v[j] == 0) {
	break;
      }
    }
  }
  return 0;
}
