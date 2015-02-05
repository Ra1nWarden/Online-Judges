#include <iostream>
#include <vector>

using namespace std;

int check(vector<string> &chess, int offset) {
  // check k
  int x, y;
  bool found = false;
  for(int i = 0; i < 8; i++) {
    if(!found){
    for(int j = 0; j < 8; j++) {
      if(chess[i][j] == 'k' - offset) {
	x = i;
	y = j;
	found = true;
	break;
      }
    }
    }
  }
  // left
  char testchar = '.';
  for(int j = y - 1;j >=0; j--) {
    if(chess[x][j] != '.') {
      testchar = chess[x][j];
      break;
    }
  }
  if(testchar == 'R'+offset || testchar == 'Q'+offset)
    return 1;
  // right
  testchar = '.';
  for(int j = y+1; j < 8; j++) {
     if(chess[x][j] != '.') {
      testchar = chess[x][j];
      break;
    }
  }
   if(testchar == 'R'+offset || testchar == 'Q'+offset)
    return 1;
   // top
   testchar = '.';
     for(int i = x-1; i >= 0; i--) {
     if(chess[i][y] != '.') {
      testchar = chess[i][y];
      break;
    }
  }
  if(testchar == 'R'+offset || testchar == 'Q'+offset)
    return 1;
  // bottom
  testchar ='.';
   for(int i = x+1; i< 8; i++) {
     if(chess[i][y] != '.') {
     testchar = chess[i][y];
      break;
     }
    }
  
 if(testchar == 'R'+offset || testchar == 'Q'+offset)
    return 1;
 // top left
 testchar = '.';
 for(int i = 1; x-i >=0 && y-i >= 0; i++) {
    if(chess[x-i][y-i] != '.') {
      testchar = chess[x-i][y-i];
      break;
    }
 }
 if(testchar == 'B'+offset || testchar == 'Q'+offset)
   return 1;
 // top right
 testchar = '.';
 for(int i = 1; x-i >=0 && y+i < 8; i++) {
    if(chess[x-i][y+i] != '.') {
      testchar = chess[x-i][y+i];
      break;
    }
 }
 if(testchar == 'B'+offset || testchar == 'Q'+offset)
   return 1;
 // bottom left
 testchar = '.';
 for(int i = 1; x+i<8 && y-i >= 0; i++) {
    if(chess[x+i][y-i] != '.') {
      testchar = chess[x+i][y-i];
      break;
    }
 }
 if(testchar == 'B'+offset || testchar == 'Q'+offset)
   return 1;
 // bottom right
 testchar = '.';
 for(int i = 1; x+i <8 && y+i < 8; i++) {
    if(chess[x+i][y+i] != '.') {
      testchar = chess[x+i][y+i];
      break;
    }
 }
 if(testchar == 'B'+offset || testchar == 'Q'+offset)
   return 1;
 // check for pawn
 if(offset == 0) {
 if(x+1 < 8) {
   if(y - 1 >= 0) {
     if(chess[x+1][y-1] == 'P')
       return 1;
   }
   if(y+1 < 8) {
     if(chess[x+1][y+1] == 'P')
       return 1;
   }
 }
 }
 else {
 if(x-1>=0) {
   if(y - 1>=0) {
     if(chess[x-1][y-1] == 'P'+offset)
       return 1;
   }
   if(y+1 < 8) {
     if(chess[x-1][y+1] == 'P'+offset)
       return 1;
   }
 }
 }
 // check for knight
if(x - 1 >= 0 && y - 2 >= 0) {
   if(chess[x-1][y-2] == 'N'+offset)
     return 1;
 }
if(x - 2 >= 0 && y - 1 >= 0) {
   if(chess[x-2][y-1] == 'N'+offset)
     return 1;
 }
if(x - 1 >= 0 && y + 2 < 8) {
   if(chess[x-1][y+2] == 'N'+offset)
     return 1;
 }
if(x - 2 >= 0 && y + 1 < 8) {
   if(chess[x-2][y+1] == 'N'+offset)
     return 1;
 }
if(x + 1 < 8 && y - 2 >= 0) {
   if(chess[x+1][y-2] == 'N'+offset)
     return 1;
 }
if(x + 2 < 8 && y - 1 >= 0) {
   if(chess[x+2][y-1] == 'N'+offset)
     return 1;
 }
if(x + 1 < 8 && y + 2 < 8) {
   if(chess[x+1][y+2] == 'N'+offset)
     return 1;
 }
if(x + 2 < 8 && y + 1 < 8) {
   if(chess[x+2][y+1] == 'N'+offset)
     return 1;
 }
 return 0;
}

int main() {
  int currentcase = 1;
  while(true) {
    vector<string> chess;
    for(int i = 0; i < 8; i++) {
      string line;
      getline(cin, line);
      chess.push_back(line);
    }
    bool test = false;
    for(int i = 0; i < 8; i++) {
      if(!test) {
      for(int j = 0; j < 8; j++) {
	if(chess[i][j] != '.') {
	  test = true;
	  break;
	}
      }
      }
    }
    if(!test)
      break;
      if(check(chess,0) == 1)
	cout << "Game #" << currentcase << ": black king is in check." << endl;
      else if(check(chess, 32) == 1)
	cout << "Game #" << currentcase << ": white king is in check." << endl;
      else
	cout << "Game #" << currentcase << ": no king is in check." << endl;
      string emptyline;
      getline(cin, emptyline);
      currentcase++;
  }
  return 0;
}
