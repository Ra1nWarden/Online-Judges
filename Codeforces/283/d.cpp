#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>

// no wrong algorithm :(

using namespace std;

int one[100001];
int two[100001];
int n;

bool possible(int div, int winnerv[], int loserv[]) {
  cout << "possible " << div << endl;
  int mult = 1;
  int loserpoints = 0;
  for(int i = 0; i < n; i++) {
    if(winnerv[i] == div * mult) {
      mult++;
      cout << "winnerv " << winnerv[i] << " and " << div << endl;
      cout << "loserpoints  " << loserpoints <<  " and " << loserv[i] << endl;
      if(div <= loserv[i] - loserpoints) {
	cout << "returning false as for i = " << i << " winnerv " << winnerv[i] << " <= loserv " << loserv[i] << endl;
	return false;
      }
      loserpoints = loserv[i];
    } else if(loserv[i] - loserpoints == div && winnerv[i] - (mult-1) * div < div)
      loserpoints = loserv[i];
  }
  return true;
}

int main() {
  memset(one, 0, sizeof one);
  memset(two, 0, sizeof two);
  cin >> n;
  int winner = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(i == n - 1)
      winner = x;
    if(x == 1) {
      one[i] = one[max(0, i - 1)] + 1;
      two[i] = two[max(0, i - 1)];
    }
    if(x == 2) {
      one[i] = one[max(0, i - 1)];
      two[i] = two[max(0, i-1)] + 1;
    }
  }
  set<pair<int, int> > results;
  int* winnerv = winner == 1 ? one : two;
  int* loserv = winner == 1 ? two : one;
  for(int i = 1; i <= sqrt(winnerv[n-1]); i++) {
    if(winnerv[n-1] % i == 0) {
      cout << "i is " << i << endl;
      if(possible(i, winnerv, loserv))
	results.insert(make_pair(winnerv[n - 1] / i, i));
      if(possible(winnerv[n-1] / i, winnerv, loserv))
	results.insert(make_pair(i, winnerv[n-1] / i));
    }
  }
  cout << results.size() << endl;
  for(set<pair<int, int> >::iterator itr = results.begin(); itr != results.end(); itr++)
    cout << itr->first << " "<< itr->second << endl;
  return 0;
}
