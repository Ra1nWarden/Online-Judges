#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct Car {
  Car(int len) : length(len) {};
  int length;
};

int main() {
  int cases; 
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int l, m;
    cin >> l >> m >> ws;
    l *= 100;
    queue<Car> leftq;
    queue<Car> rightq;
    for(int j = 0; j < m; j++) {
      string line;
      getline(cin, line);
      istringstream iss(line.c_str());
      int length;
      string side;
      iss >> length >> side;
      if(side == "left")
	leftq.push(Car(length));
      else
	rightq.push(Car(length));
    }
    bool left = true;
    int ferry = l;
    int result = 0;
    while(true) {
      if(leftq.empty() && rightq.empty())
	break;
      ferry = l;
      while(true) {
	if(left) {
	  if (leftq.empty())
	    break;
	  Car next = leftq.front();
	  if (next.length > ferry)
	    break;
	  leftq.pop();
	  ferry -= next.length;
	}
	else {
	  if (rightq.empty())
	    break;
	  Car next = rightq.front();
	  if (next.length > ferry)
	    break;
	  rightq.pop();
	  ferry -= next.length;
	}
      }
      left = !left;
      result++;
    }
    cout << result << endl;
  }
  return 0;
}
