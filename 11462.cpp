#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  while(true) {
    int counts;
    cin >> counts;
    if(counts == 0)
      break;
    set<int> unique;
    map<int, int> countMap;
    for(int i= 0; i < counts; i++) {
      int age;
      cin >> age;
      unique.insert(age);
      countMap[age] = countMap[age] + 1;
    }
    cout << *unique.begin();
    for(set<int>::iterator itr = unique.begin(); itr != unique.end(); ++itr) {
      int freq = countMap[*itr];
      if (itr == unique.begin())
	freq--;
      for(int j = 0; j < freq; j++)
	cout << " " << *itr;
    }
    cout << endl;
  }
  return 0;
}
