#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct turtle {
  int weight;
  int carry;
  int stacks;
  turtle(int a, int b) : weight(a), carry(b), stacks(1) {};
};

bool compare(turtle* a, turtle* b) {
  if(a->carry != b->carry)
    return a->carry < b->carry;
  else
    return a->weight > b->weight;
}

int main() {
  vector<turtle*> turtles;
  while(!cin.eof()) {
    int weight, carry;
    cin >> weight >> carry;
    turtle* current = new turtle(weight, carry);
    turtles.push_back(current);
  }
  sort(turtles.begin(), turtles.end(), compare);
  for(int i = 0; i < turtles.size(); i++) {
    turtle* current = turtles[i];
    int maxweight= current->weight; 
    int maxstacks = current->stacks;
    for(int j = 0; j < i; j++) {
      turtle* smaller = turtles[j];
      if(smaller->weight + current->weight <= current-> carry) {
	if(smaller->stacks + 1 > maxstacks) {
	  maxstacks = smaller->stacks + 1;
	  maxweight = smaller->weight + current->weight;
	}
      }
    }
    current->stacks = maxstacks;
    current->weight = maxweight;
  }
  int result = 0;
  for(int i= 0; i < turtles.size(); i++) {
    if(turtles[i]->stacks > result)
      result = turtles[i]->stacks;
  }
  cout << result << endl;
  return 0;
}
