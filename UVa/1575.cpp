#include <cstdio>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

typedef unsigned long long LL;
map<LL, LL> ans;
const LL maxVal = 1ULL << 63;
vector<int> primes;

vector<int> generatePrime(int x) {
  bool check[x+1];
  memset(check, false, sizeof check);
  vector<int> result;
  for(int i = 2; i <= x; i++) {
    if(!check[i])
      result.push_back(i);
    for(int j = 0; j < result.size(); j++) {
      if(i * result[j] > x)
	break;
      check[i * result[j]] = true;
      if(i % result[j] == 0)
	break;
    }
  }
  return result;
}

void updateAns(vector<int> counts, LL product) {
  LL res = 1;
  LL num = 1;
  for(int i = 0; i < counts.size(); i++) {
    for(int j = 1; j <= counts[i]; j++) {
      if(res % j == 0) {
	res /= j;
	if(maxVal / res < num)
	  return;
	res *= num++;
      } else {
	if(maxVal / res < num / j)
	  return;
	res *= (num / j);
	num++;
      }
    }
  }
  if(ans.count(res))
    ans[res] = min(ans[res], product);
  else
    ans[res] = product;
}

void generateAns(vector<int> counts, LL product) {
  LL maxPrime = maxVal / product;
  int nextPrime = primes[counts.size()];
  if(maxPrime >= nextPrime) {
    vector<int> newcounts = counts;
    newcounts.push_back(1);
    updateAns(newcounts, product*nextPrime);
    generateAns(newcounts, product*nextPrime);
  }
  if(counts.size() > 0) {
    int prevPrime = primes[counts.size() - 1];
    if(maxPrime >= prevPrime && (counts.size() == 1 || counts[counts.size() - 1] < counts[counts.size() - 2])) {
      vector<int> newcounts = counts;
      newcounts[newcounts.size() - 1]++;
      updateAns(newcounts, product*prevPrime);
      generateAns(newcounts, product*prevPrime);
    }
  }
}

int main() {
  LL n;
  primes = generatePrime(100);
  vector<int> counts;
  generateAns(counts, 1ULL);
  while(scanf("%llu", &n) != EOF) {
    printf("%llu %llu\n", n, ans[n]);
  }
  return 0;
}
