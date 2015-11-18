#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> coeffs;
vector<int> powers;
int mod;

void parse(string line) {
  coeffs.clear();
  powers.clear();
  int slash;
  for(int i = 0; i < line.length(); i++) {
    if(line[i] == '/') {
      slash = i;
      break;
    }
  }
  mod = atoi(line.substr(slash + 1).c_str());
  string poly = line.substr(1, slash - 2);
  int i = 0;
  while(i < poly.length()) {
    bool neg = false;
    if(poly[i] == '-') {
      neg = true;
      i++;
    } else if(poly[i] == '+') {
      i++;
    }
    int j = i;
    while(j < poly.length() && !(poly[j] == '+' || poly[j] == '-')) {
      j++;
    }
    string term = poly.substr(i, j - i);
    int got_n = -1;
    for(int idx = 0; idx < term.length(); idx++) {
      if(term[idx] == 'n') {
	got_n = idx;
	break;
      }
    }
    if(got_n == -1) {
      powers.push_back(0);
      int coeff = atoi(term.c_str());
      if(neg)
	coeff = -coeff;
      coeffs.push_back(coeff);
    } else {
      int coeff = 1;
      if(got_n > 0) {
	coeff = atoi(term.substr(0, got_n).c_str());
      }
      if(neg)
	coeff = -coeff;
      coeffs.push_back(coeff);
      int power = 1;
      if(got_n < term.length() - 1) {
	power = atoi(term.substr(got_n + 2).c_str());
      }
      powers.push_back(power);
    }
    i = j;
  }
}

int calc(int b, int p) {
  if(p == 0)
    return 1 % mod;
  if(p == 1)
    return b % mod;
  int ans = calc(b, p / 2);
  ans = (ans * 1LL * ans) % mod;
  if(p % 2)
    ans = (ans * 1LL * b) % mod;
  return ans;
}

int eval(int x) {
  int ans = 0;
  for(int i = 0; i < coeffs.size() && i < powers.size(); i++) {
    ans = ((long long) ans + (coeffs[i] * 1LL * calc(x, powers[i])) % mod) % mod;
  }
  return ans;
}

bool check() {
  if(mod == 0)
    return false;
  for(int i = 1; i <= powers[0] + 1; i++) {
    int num = eval(i);
    if(num != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  string line;
  int kase = 1;
  while(getline(cin, line)) {
    if(line == ".")
      break;
    parse(line);
    if(check()) {
      cout << "Case " << kase++ << ": Always an integer" << endl;
    } else {
      cout << "Case " << kase++ << ": Not always an integer" << endl;
    }
  }
  return 0;
}
