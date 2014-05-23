#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct Car {
  Car(int arr, string s, int i) : arrival(arr), side(s), index(i) {};
  int arrival;
  string side;
  int index;
};

int main() {
  int cases; 
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    if(i != 0)
      cout << endl;
    int n, t, m;
    cin >> n >> t >> m >> ws;
    queue<Car> carqueue;
    for(int j = 0; j < m; j++) {
      string line;
      getline(cin, line);
      istringstream iss(line.c_str());
      int arrival;
      string side;
      iss >> arrival >> side;
      carqueue.push(Car(arrival, side, j));
    }
    bool left = true;
    int time = 0;
    queue<Car> leftq;
    queue<Car> rightq;
    queue<Car> ferry;
    vector<int> result(m);
    while(true) {
      while(!carqueue.empty() && carqueue.front().arrival <= time) {
	Car dequeued = carqueue.front();
	carqueue.pop();
	if(dequeued.side == "left")
	  leftq.push(dequeued);
	else
	  rightq.push(dequeued);
      }
      while(!ferry.empty()) {
	Car unloaded = ferry.front();
	result[unloaded.index] = time;
	ferry.pop();
      }
      if(carqueue.empty() && leftq.empty() && rightq.empty())
	break;
      // wait for the next car to arrive
      if(leftq.empty() && rightq.empty()) {
	time = carqueue.front().arrival;
	continue;
      }
      // load (if any) and return to the other side
      else {
	if(left) {
	  while((!leftq.empty()) && (ferry.size() != n)) {
	    Car fromleft = leftq.front();
	    leftq.pop();
	    ferry.push(fromleft);
	  }
	}
	else {
	  while((!rightq.empty()) && (ferry.size() != n)) {
	    Car fromright = rightq.front();
	    rightq.pop();
	    ferry.push(fromright);
	  }
	}
	left = !left;
	time += t;
      }
    }
    for(int l = 0; l < m; l++)
      cout << result[l] << endl;
  }
  return 0;
}
