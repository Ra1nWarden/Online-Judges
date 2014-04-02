#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {
    char product[250][250];
    for(int j = 0; j < 250; j++) {
      for(int i = 0; i < 250; i++) {
	product[j][i] = 'O';
      }
    }
  while(true) {
    string line;
    getline(cin, line);
    istringstream in (line.c_str());
    char cmd;

    // int[y][x] corresponds to (x, y) (m, n)
    int m, n;
    in >> cmd;
    switch (cmd) {
      int x, y, x1, x2, y1, y2;
      char color;
    case 'X': {
      return 0;
    }
    case 'I':{
      in >> m >> n;
      for(int j = 0; j < n; j++) {
      for(int i = 0; i < m; i++) {
	product[j][i] = 'O';
      }
    }
      break;
    }
    case 'C': {
      for(int j = 0; j < n; j++) {
	for(int i = 0; i < m; i++) {
	  product[j][i] = 'O';
	}
      }
      break;
    }
    case 'L': {
      in >> x >> y >> color;
      if(y <= n && x <= m)
	product[y-1][x-1] = color;
      break;
    }
    case 'V': {
      in >> x >> y1 >> y2 >> color;
      if(y2 < y1) {
	int temp = y1;
	y1 = y2;
	y2 = temp;
      }
      if(x <= m) {
	for(int j = y1-1; j < y2 && j < n; j++)
	  product[j][x-1] = color;
      }
      break;
    }
    case 'H': {
      in >> x1 >> x2 >> y >> color;
      if(x2 < x1) {
	int temp = x1;
	x1 = x2;
	x2 = temp;
      }
      if(y <= n) {
      for(int i = x1-1; i < x2 && i < m; i++)
	product[y-1][i] = color;
      }
      break;
    }
    case 'K': {
      in >> x1 >> y1 >> x2 >> y2 >> color;
      if(y2 < y1) {
	int temp = y1;
	y1 = y2;
	y2 = temp;
      }
      if(x2 < x1) {
	int temp = x1;
	x1 = x2;
	x2 = temp;
      }
      for(int j = y1-1; j < y2 && j < n; j++) {
	for(int i = x1-1; i < x2 && i < m; i++)
	  product[j][i] = color;
      }
      break;
    }
    case 'F': {
      in >> x >> y >> color;
      if(x <= m && y <= n) {
      set<int> row;
      row.insert(y);
      set<int> col;
      col.insert(x);
      int roworigsize, colorigsize;
      char currentcolor = product[y-1][x-1];
      do {
	roworigsize = row.size();
	colorigsize = col.size();
	for(set<int>::iterator itr = row.begin(); itr != row.end(); ++itr) {
	  int currentrow = *itr;
	  for(int i = 0; i < m; i++) {
	    if(product[currentrow-1][i] == currentcolor)
	      col.insert(i+1);
	  }
	}
	for(set<int>::iterator itr = col.begin(); itr != col.end(); ++itr) {
	  int currentcol = *itr;
	  for(int j = 0; j < n; j++) {
	    if(product[j][currentcol - 1] == currentcolor)
	      row.insert(j+1);
	  }
	}
      } while (roworigsize != row.size() || colorigsize != col.size());
	for(int j = 0; j < n; j++) {
	  for(int i = 0; i < m; i++) {
	    if(row.count(j+1) != 0 || col.count(i+1) != 0) {
	      if(product[j][i] == currentcolor)
		product[j][i] = color;
	    }
	  }
	}
	break;
      }
}
    case 'S':{
      string name;
      in >> name;
      cout << name << endl;
      for(int j = 0; j < n; j++) {
	for(int i = 0; i < m; i++) {
	  cout << product[j][i];
	}
	cout << endl;
      }
      break;
    }
    }
  }
  return 0;
}
