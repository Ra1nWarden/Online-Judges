#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int vectorToNum(vector<int>& digits) {
  int result = 0;
  for(int i = 0; i < 4; i++)
    result += ((int) pow(10.0, 3 - i) * digits[i]);
  return result;
}
 
struct node {
  vector<int> digits;
  int shortest;
  node(int number) : shortest(0), digits(4) {
    for(int i = 0; i < 4; i++) {
      digits[3 - i] = number % 10;
      number /= 10;
    }
  };
  node(vector<int> digit) : digits(digit),shortest(0) {};
  bool operator==(node& compared) {
    for(int i = 0; i < 4; i++) {
      if(digits[i] != compared.digits[i])
	return false;
    }
    return true;
  };
};

node* readnode(map<int, node*>& grid) {
  int start = 0;
  for(int x = 0; x < 4; x++) {
      int number;
      cin >> number;
      start += ((int) pow(10.0, 3 - x) * number);
  }
  return grid[start];
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    cin >> ws;
    map<int, node*> currentGrid;
    for(int i = 0; i < 10000; i++) {
      node* newNode = new node(i);
      currentGrid[i] = newNode;
    }
    node* start = readnode(currentGrid);
    node* end = readnode(currentGrid);
    int exclude;
    cin >> exclude;
    vector<node*> excludelist;
    for(int j = 0; j < exclude; j++) {
      node* current = readnode(currentGrid);
      excludelist.push_back(current);
    }
    if(start == end) {
      cout << 0 << endl;
      continue;
    }
    queue<node*> searchList;
    searchList.push(start);
    bool found = true;
    while(end->shortest == 0) {
      node* processing = searchList.front();
      // process neighbours
      for(int k = 0; k < 4; k++) {
	vector<int> numberinvector = processing->digits;
	if(numberinvector[k] == 9)
	  numberinvector[k] = 0;
	else
	  numberinvector[k]++;
	node* up = currentGrid[vectorToNum(numberinvector)];
	if(count(excludelist.begin(), excludelist.end(), up) != 1) {
	  if(up->shortest == 0) {
	    up->shortest = processing->shortest + 1;
	    searchList.push(up);
	  }
	}
	numberinvector = processing->digits;
	if(numberinvector[k] == 0)
	  numberinvector[k] = 9;
	else
	  numberinvector[k]--;
	node* down = currentGrid[vectorToNum(numberinvector)];
	if(count(excludelist.begin(), excludelist.end(), down) != 1) {
	  if(down->shortest == 0) {
	    down->shortest = processing->shortest + 1;
	    searchList.push(down);
	  }
	}
      }
      searchList.pop();
      if(searchList.size() == 0) {
	found = false;
	break;
      }
    }
    if(found)
      cout << end->shortest << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
