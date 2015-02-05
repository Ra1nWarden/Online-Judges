#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

bool num[46341];
vector<int> prime;

int main() {
  memset(num, true, sizeof num);
  for(int i = 2; i < 46341; i++) {
    if(num[i]) {
      prime.push_back(i);
      for(int j = i + i; j < 46341; j+=i)
	num[j] = false;
    }
  }
  int x;
  while(cin >> x) {
    map<int, int> facts;
    int xcopy = x;
    for(int i= 0; i < prime.size(); i++) {
      int nextprime = prime[i];
      if(xcopy % nextprime == 0) {
	int count = 0;
	while(xcopy % nextprime == 0) {
	  count++;
	  xcopy /= nextprime;
	}
	facts[nextprime] = count;
      }
    }
    if(xcopy != 1)
      facts[xcopy] = 1;
    int coprime = x;
    int fact = 1;
    for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
      //cout << "factor: " << itr->first << " " << itr->second << endl;
      coprime = coprime / itr->first * (itr->first - 1);
      fact = fact * (itr->second + 1);
    }
    //cout << x << " " << coprime << " " << fact << endl;
    cout << x - coprime - fact + 1 << endl;
    
  }

  return 0;
}
