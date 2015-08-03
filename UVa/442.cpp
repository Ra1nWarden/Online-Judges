#include <iostream>
#include <sstream>
#include <stack>
#define MAXN 30

using namespace std;

typedef pair<int, int> Mat;

Mat matrices[MAXN];
int n, ans;

bool solve(string line) {
  stack<Mat> s;
  for(int i = 0; i < line.length(); i++) {
    if(line[i] == '(')
      continue;
    else if(line[i] == ')') {
      Mat b = s.top();
      s.pop();
      Mat a = s.top();
      s.pop();
      if(a.second != b.first)
	return false;
      ans += a.first * a.second * b.second;
      s.push(make_pair(a.first, b.second));
    } else {
      s.push(matrices[line[i] - 'A']);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  string line;
  getline(cin, line);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    stringstream ss(line.c_str());
    char c;
    ss >> c;
    int m, n;
    ss >> m >> n;
    matrices[c - 'A'].first = m;
    matrices[c - 'A'].second = n;
  }
  while(getline(cin, line)) {
    ans = 0;
    if(solve(line)) {
      cout << ans << endl;
    } else {
      cout << "error" << endl;
    }
  }
  return 0;
}
