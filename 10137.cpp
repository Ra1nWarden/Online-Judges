#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int number;
  while(cin >> number) {
    if(number == 0)
      break;
    vector<double> sets;
    int sum = 0;
    for(int i = 0 ; i < number; i++) {
      double current;
      cin >> current;
      sets.push_back(current);
      sum += (current * 100);
    }
    sort(sets.begin(), sets.end(), greater<double>());
    int average = sum / number;
    int residue = sum % number;
    double result = 0;
    double target[number];
    for(int i = 0; i < number; i++)
      target[i] = ((double) average) / 100;
    for(int i = 0; i < residue; i++)
      target[i] += 0.01;
    for(int i = 0; i < number; i++) {
      if(sets[i] > target[i])
	result += (sets[i] - target[i]);
    }
    cout << "$" << fixed << setprecision(2) << result << endl;
  }
  return 0;
}
