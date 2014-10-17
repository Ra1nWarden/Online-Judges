#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  int caseNo = 1;
  while(cases--){
    int n;
    cin >> n;
    vector<int> heights;
    vector<int> widths;
    vector<int> lis;
    vector<int> lds;
    int x;
    for(int i= 0; i < n; i++) {
      cin >> x;
      heights.push_back(x);
    }
    int longestlis = 0;
    int longestlds = 0;
    for(int i= 0; i < n; i++) {
      cin >> x;
      widths.push_back(x);
      lis.push_back(x);
      lds.push_back(x);
      if(x > longestlis) {
	longestlis = x;
	longestlds = x;
      }
    }
    for(int i=1; i< n; i++) {
      for(int j= 0; j < i; j++) {
	if(heights[i] > heights[j]) {
	  lis[i] = max(lis[i], lis[j] + widths[i]);
	  if(lis[i] > longestlis)
	    longestlis = lis[i];
	}
      }
    }
    for(int i = 1; i < n; i++) {
      for(int j= 0; j < i; j++) {
	if(heights[i] < heights[j]) {
	  lds[i] = max(lds[i], lds[j] + widths[i]);
	  if(lds[i] > longestlds)
	    longestlds = lds[i];
	}
      }
    }
    if(longestlis >= longestlds) {
      cout << "Case " << caseNo << ". Increasing (" << longestlis << "). Decreasing (" << longestlds << ")." << endl;
    }
    else {
      cout << "Case " << caseNo << ". Decreasing (" << longestlds << "). Increasing (" << longestlis << ")." << endl;
    }
    caseNo++;
  }
  return 0;
}
