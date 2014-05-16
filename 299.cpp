#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int bubblesortCount(vector<int>& vec) {
  int result = 0;
  while(true) {
    bool swapped = false;
    for(int i = 0; i < vec.size() - 1; i++) {
      if(vec[i] > vec[i+1]) {
	swapped = true;
	swap(vec[i], vec[i+1]);
	result++;
      }
    }
    if(!swapped)
      break;
  }
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int total;
    cin >> total >> ws;
    string line;
    getline(cin, line);
    istringstream iss(line.c_str());
    vector<int> number;
    int each;
    while(iss >> each)
      number.push_back(each);
    int counts = bubblesortCount(number);
    cout << "Optimal train swapping takes " << counts << " swaps." << endl;
  }
  return 0;
}
