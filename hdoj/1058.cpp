#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#define MAXN 5900
#define INF 4000000000LL

using namespace std;

long long v[MAXN];
int idx;
int p[] = {2,3,5,7};
int pi[] = {1,1,1,1};

string num_to_string(int num) {
  stringstream ss;
  ss << num;
  if(num % 100 >= 10 && num % 100 < 20) {
    ss << "th";
  } else if(num % 10 == 1) {
    ss << "st";
  } else if(num % 10 == 2) {
    ss << "nd";
  } else if(num % 10 == 3) {
    ss << "rd";
  } else {
    ss << "th";
  }
  return ss.str();
}

int main() {
  idx = 1;
  v[idx++] = 1;
  while(idx <= 5842) {
    long long num = INF;
    for(int i = 0; i < 4; i++)
      num = min(num, v[pi[i]] * p[i]);
    for(int i = 0; i < 4; i++) {
      if(v[pi[i]] * p[i] == num) {
	pi[i]++;
	break;
      }
    }
    if(num != v[idx-1])
      v[idx++] = num;
  }
  int q;
  while(scanf("%d", &q) != EOF && q) {
    printf("The %s humble number is %I64d.\n", num_to_string(q).c_str(), v[q]);
  }
  return 0;
}
