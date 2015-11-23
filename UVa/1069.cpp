#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<long long> coeffs;
vector<int> powers;
int mod;

void parse(string str) {
  coeffs.clear();
  powers.clear();
  // int slash;
  // for(int i = 0; i < line.length(); i++) {
  //   if(line[i] == '/') {
  //     slash = i;
  //     break;
  //   }
  // }
  // mod = atoi(line.substr(slash + 1).c_str());
  // string poly = line.substr(1, slash - 2);
  // int i = 0;
  // while(i < poly.length()) {
  //   bool neg = false;
  //   if(poly[i] == '-') {
  //     neg = true;
  //     i++;
  //   } else if(poly[i] == '+') {
  //     i++;
  //   }
  //   int j = i;
  //   while(j < poly.length() && !(poly[j] == '+' || poly[j] == '-')) {
  //     j++;
  //   }
  //   string term = poly.substr(i, j - i);
  //   int got_n = -1;
  //   for(int idx = 0; idx < term.length(); idx++) {
  //     if(term[idx] == 'n') {
  // 	got_n = idx;
  // 	break;
  //     }
  //   }
  //   if(got_n == -1) {
  //     powers.push_back(0);
  //     long long coeff = atoll(term.c_str());
  //     if(neg)
  // 	coeff = -coeff;
  //     coeffs.push_back(coeff % mod);
  //   } else {
  //     long long coeff = 1;
  //     if(got_n > 0) {
  // 	coeff = atoll(term.substr(0, got_n).c_str());
  //     }
  //     if(neg)
  // 	coeff = -coeff;
  //     coeffs.push_back(coeff);
  //     int power = 1;
  //     if(got_n < term.length() - 1) {
  // 	power = atoi(term.substr(got_n + 2).c_str());
  //     }
  //     powers.push_back(power);
  //   }
  //   i = j;
  // }

  long long k = 0, a = 0, key = 0, sign = 1;
  mod = 0;
  for(int i = 0; i <= str.length(); i++) {
    if(isdigit(str[i])) {
      if(key == 0) {
	a = a * 10 + str[i] - '0';
      } else if(key == 1) {
	k = k * 10 + str[i] - '0';
      } else if(key == 2) {
	mod = mod * 10 + str[i] - '0';
      } 
    } else if(str[i] == '/') {
      key = 2;
    } else if(str[i] == 'n') {
      key = 1;
    } else if(str[i] == '-' || str[i] == '+' || str[i] == ')') {
      if(key >= 1) {
	if(k == 0)
	  k = 1;
	if(a == 0)
	  a = 1;
      }

      coeffs.push_back(a * sign);
      powers.push_back(k);

      if(str[i] == '-')
	sign = -1;
      else
	sign = 1;

      key = a = k = 0;
    }
  }
}

long long calc(int x, int n) {
  long long ans = 1;
  while(n) {
    if(n & 1)
      ans = (ans * x) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return ans;
}

long long eval(long long x) {
  long long ans = 0;
  for(int i = 0; i < coeffs.size() && i < powers.size(); i++) {
    ans = (ans + (coeffs[i] * 1LL * calc(x, powers[i])) % mod) % mod;
  }
  return ans;
}

bool check() {
  for(int i = 1; i <= powers[0] + 1; i++) {
    long long num = eval(i);
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
