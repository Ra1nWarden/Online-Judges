#include <iostream>
#include <vector>
#include <cstring>

#define FAIL -1000

using namespace std;

bool DEBUG = false;

int memo[201][21];

// return moneyleft
int shop(int moneyleft, vector<vector<int> > prices, int index) {
  if(DEBUG)
    cout << "calling moneyleft " << moneyleft << " index is  " << index << endl;
  if(moneyleft < 0) {
    return FAIL;
  }
  if(index == prices.size())
    return moneyleft;
  if(memo[moneyleft][index] != -1) {
    return memo[moneyleft][index];
  }
  vector<int> price = prices[index];
  int min = FAIL;
  for(int i= 0; i < price.size(); i++) {
    int nextleft = shop(moneyleft - price[i], prices, index+1);
    if(min == FAIL || (nextleft <= min && nextleft >= 0))
      min = nextleft;
  }
  memo[moneyleft][index] = min;
  return min;
}

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int money, count;
    cin >> money >> count;
    vector<vector<int> > prices;
    for(int j= 0; j < count; j++) {
      vector<int> row;
      int count2;
      cin >> count2;
      for(int k = 0; k < count2; k++) {
	int p;
	cin >> p;
	row.push_back(p);
      }
      prices.push_back(row);
    }
    memset(memo, -1, sizeof memo);
    int result = shop(money, prices, 0);
    if(result == FAIL) {
      cout << "no solution" << endl;
    } else {
      cout << money - result << endl;
    }
  }
  return 0;
}

