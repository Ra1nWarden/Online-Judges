#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

string input;
int sum;

// always called from the root of a tree
bool result(int& index, int runSum, bool& hasChildren) {
  if(index >= input.length())
    return false;
  //cout << "at index " << index << " runSum is " << runSum << endl;
  if(input[index+1] == ')') {
    index += 2;
    return false;
  } else {
    hasChildren = true;
    int numberLength = 1;
    while(input[index+numberLength] != ')' && input[index+numberLength] != '(')
      numberLength++;
    int number = atoi(input.substr(index + 1, numberLength - 1).c_str());
    index += numberLength;
    //cout << "numberlength is " << numberLength << " number is " << number << endl;
    //cout << "after increasing, index is " << index << endl;
    bool leftChild = false;
    bool rightChild = false;
    bool leftFound = result(index, runSum + number, leftChild);
    bool rightFound = result(index, runSum + number, rightChild);
    index++;
    if(leftFound || rightFound)
      return true;
    else if(!leftChild && !rightChild) {
      return runSum + number == sum ? true : false;
    } else {
      return false;
    }
  }
}

int main() {
  while(cin >> sum) {
    char c;
    int open = 0, close = 0;
    input = "";
    while(cin >> c) {
      if(c == '(')
	open++;
      else if(c == ')')
	close++;
      input += c;
      if(open == close)
	break;
    }
    int index = 0;
    bool empty = false;
    //cout << input << endl;
    cout << (result(index, 0, empty) ? "yes" : "no") << endl;
  }
  return 0;
}
