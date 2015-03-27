#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while(cin >> n) {
    vector<int> v(n);
    vector<int> start(n);
    vector<int> length(n);
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      start[i] = i;
      length[i] = 1;
    }
    int lis = 1;
    for(int i = 1; i < n; i++) {
      int large = v[i];
      for(int j = 0; j < i; j++) {
	if(large > v[j] && length[j] + 1 > length[i]) {
	  length[i] = length[j] + 1;
	  start[i] = start[j];
	  lis = max(lis, length[i]);
	} 
      }
    }

    long long result = 0;
    vector<int> boundaryr;
    boundaryr.push_back(0)

  }
  return 0;
}
