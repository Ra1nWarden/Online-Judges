#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  while(true) {
    int length;
    cin >> length;
    if(length == 0)
      break;
    int cutcount;
    cin >> cutcount;
    vector<int> cuts;
    cuts.push_back(0);
    for(int i = 0; i < cutcount; i++) {
      int cut;
      cin >> cut;
      cuts.push_back(cut);
    }
    cuts.push_back(length);
    vector<vector<int> > counts;
    for(int i= 0; i < cutcount+2; i++) {
      vector<int> row;
      for(int j = 0; j < cutcount+2; j++)
	row.push_back(0);
      counts.push_back(row);
    }
    for(int d = 2; d <= cutcount+1; d++) {
      for(int i = 0; i+d <= cutcount+1; i++) {
	int min = INT_MAX;
	for(int j = i+1; j < i+d; j++) {
	  int current = (cuts[i+d]-cuts[i])+counts[i][j]+counts[j][i+d];
	  if(current < min)
	    min = current;
	}
	counts[i][i+d] = min;
      }
    }
    cout << "The minimum cutting is " << counts[0][cutcount+1] << ".\n";
  }

}
