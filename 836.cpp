#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

bool DEBUG = false;

int main() {
  int cases;
  cin >> cases >> ws;
  string line;
  for(int i= 0; i < cases; i++) {
    if(i > 0)
      cout << endl;
    vector<vector<int> > v;
    while(getline(cin, line)) {
      if(line.length() == 0)
	break;
      else {
	vector<int> row;
	for(int j = 0; j < line.length(); j++) {
	  if(line[j] == '0')
	    row.push_back(0);
	  else if(line[j] == '1')
	    row.push_back(1);
	}
	v.push_back(row);
      }
    }
    if(DEBUG) {
      cout << "printing v matrix" << endl;
      for(int j = 0; j < v.size(); j++) {
	for(int k = 0; k < v[0].size(); k++) {
	  cout << v[j][k] << " " ;
	}
	cout << endl;
      }
      cout << endl;
    }
    int r = v.size();
    int c = v[0].size();
    int sum[r][c];
    memset(sum, 0, sizeof sum);
    for(int j = 0; j < r; j++) {
      for(int k = 0; k < c; k++) {
	int subsum = v[j][k];
	if(j > 0)
	  subsum += sum[j-1][k];
	if(k > 0)
	  subsum += sum[j][k-1];
	if(j > 0 && k > 0)
	  subsum -= sum[j-1][k-1];
	sum[j][k] = subsum;
      }
    }
    if(DEBUG) {
      cout << "sum matrix" << endl;
      for(int j = 0; j < r; j++) {
	for(int k = 0; k < c; k++) {
	  cout << sum[j][k] << " ";
	}
	cout << endl;
      }
      cout << endl;
    }
    int result = 0;
    for(int j = 0; j < r; j++) {
      for(int k = 0; k < c; k++) {
	for(int l = j; l < r; l++) {
	  for(int m = k; m < c; m++) {
	    int subsum = sum[l][m];
	    if(j > 0)
	      subsum -= sum[j-1][m];
	    if(k > 0)
	      subsum -= sum[l][k-1];
	    if(j > 0 && k > 0)
	      subsum += sum[j-1][k-1];
	    if(subsum == (l-j + 1) * (m - k + 1)) {
	      result = max(result, subsum);
	    }
	  }
	}
      }
    }
    cout << result << endl;
  }
  return 0;
}
