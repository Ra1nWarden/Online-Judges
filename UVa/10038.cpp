#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
  while(!cin.eof()) {
    int numbers;
    cin >> numbers;
    if(numbers <= 0)
      continue;
    vector<long long> sequence;
    for(int i = 0; i < numbers; i++) {
      long long num;
      cin >> num;
      sequence.push_back(num);
    }
    vector<int> ticks(numbers, 0);
    ticks[0] = 1;
    bool test = true;
    for(int i = 1; i < numbers; i++) {
      long long nextindex = abs(sequence[i] - sequence[i-1]);
      if(nextindex > numbers - 1) {
	test = false;
	break;
      }
      else if (ticks[nextindex] == 1) {
	test = false;
	break;
      }
      else
	ticks[nextindex] = 1;
    }
    if(test)
      cout << "Jolly" << endl;
    else
      cout << "Not jolly" << endl;
    cin >> ws;
  }
}
