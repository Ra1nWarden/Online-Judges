#include <cstdio>
#include <cstring>
#include <list>
#define MAXN 100005

using namespace std;

char buff[MAXN];
int d, n;

int main() {
  while(scanf("%d %d\n", &n, &d) != EOF && (d || n)) {
    scanf("%s\n", buff);
    list<int> numbers;
    for(int i = 0; buff[i]; i++) {
      numbers.push_back(buff[i] - '0');
    }
    list<int>::iterator hd = numbers.begin(), tl = numbers.begin();
    tl++;
    while(d && tl != numbers.end()) {
      if(*hd < *tl) {
	numbers.erase(hd);
	if(tl != numbers.begin())
	  tl--;
	hd = tl;
	tl++;
	d--;
      } else {
	hd++;
	tl++;
      }
    }
    while(d) {
      numbers.pop_back();
      d--;
    }
    for(list<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
      printf("%d", *itr);
    }
    printf("\n");
  }
  return 0;
}
