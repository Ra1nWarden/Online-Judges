#include <cstdio>
#include <string>

using namespace std;

string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string onetens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
  int n;
  scanf("%d", &n);
  if(n < 10) {
    printf("%s\n", digits[n].c_str());
  } else if(n < 20) {
    printf("%s\n", onetens[n - 10].c_str());
  } else {
    if(n % 10 == 0)
      printf("%s\n", tens[n / 10 - 2].c_str());
    else
      printf("%s-%s\n", tens[n / 10 - 2].c_str(), digits[n % 10].c_str());
  }
  return 0;
}
