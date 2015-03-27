#include <cstdio>
#include <string>

using namespace std;

string useUp(string res, int sum) {
  //printf("begin res is %s, sum is %d\n", res.c_str(), sum);
  for(int i = 0; i < res.length(); i++)
    sum -= (res[i] - '0');
  for(int i = res.length() - 1; i >= 0; i--) {
    int add = min('9' - res[i], sum);
    res[i] += add;
    sum -= add;
    if(sum == 0)
      break;
  }
  //printf("res is %s, sum is %d\n", res.c_str(), sum);
  while(sum != 0) {
    if(sum > 9) {
      res = '9' + res;
      sum -= 9;
    } else {
      res = (char) ('0' + sum) + res;
      break;
    }
  }
  return res;
}

string solve(string lim, int sum) {
  int limsum = 0;
  for(int i = 0; i < lim.length(); i++)
    limsum += (lim[i] - '0');
  if(limsum < sum) {
    return useUp(lim, sum);
  } else if(limsum == sum) {
    int subindex = -1;
    string res = lim;
    for(int i = res.length() - 1; i >= 0; i--) {
      if(res[i] != '0') {
	res[i]--;
	subindex = i;
	break;
      }
    }
    bool added = false;
    for(int i = subindex - 1; i >= 0; i--) {
      if(res[i] != '9') {
	res[i]++;
	added = true;
	break;
      } else {
	res[i] = '0';
      }
    }
    if(!added)
      res = '1'+res;
    return useUp(res, sum);
  } else {
    string res = lim;
    int subindex = -1;
    for(int i = res.length() - 1; i >= 0; i--) {
      limsum -= (res[i] - '0');
      res[i] = '0';
      if(limsum < sum) {
	subindex = i;
	break;
      }
    }
    bool added = false;
    for(int i = subindex - 1; i>= 0; i--) {
      if(res[i] != '9') {
	res[i]++;
	added = true;
	break;
      } else {
	res[i] = '0';
      }
    }
    if(!added)
      res = '1' + res;
    return useUp(res, sum);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  string sol = "0";
  //printf("%s\n", solve("91", 10).c_str());
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sol = solve(sol, x);
    printf("%s\n", sol.c_str());
  }
  return 0;
} 
