#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXL 105
#define EPS 1e-6

using namespace std;

char str[MAXL];
int l;

int main() {
  while(scanf("%s\n", str) != EOF) {
    l = strlen(str);
    int shoot_cnt = 0, shoot_load = 0;
    int loaded = 0;
    for(int i = 0; i < l; i++) {
      if(str[i] == '0') {
	shoot_cnt++;
	if(str[(i+1) % l] == '1')
	  shoot_load++;
      } else
	loaded++;
    }
    double shoot_prob = shoot_load * 1.0 / shoot_cnt;
    double rotate_prob = loaded * 1.0 / l;
    if(fabs(shoot_prob - rotate_prob) < EPS)
      printf("EQUAL\n");
    else if(shoot_prob > rotate_prob)
      printf("ROTATE\n");
    else
      printf("SHOOT\n");
  }
  return 0;
}
