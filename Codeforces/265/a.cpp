#include <cstdio>
#define MAXN 1005

using namespace std;

char str[MAXN];

int main() {
  int n, p;
  scanf("%d %d\n", &n, &p);
  scanf("%s\n", str);
  if(p < 3) {
    if(n > 2) {
      printf("NO\n");
      return 0;
    }
  }
  if(n == 1) {
    if(str[0] - 'a' + 1 < p) {
      printf("%c\n", str[0]+1);
      str[0] += 1;
    } else {
      printf("NO\n");
    }
  } else if(n == 2){
    bool ok = false;
    int add = 1;
    while(str[1] + add - 'a' + 1 <= p) {
      if(str[1] + add != str[0]) {
	printf("%c%c\n", str[0], str[1] + add);
	str[1] += add;
	ok = true;
	break;
      }
      add++;
    }
    if(!ok) {
      if(str[0] - 'a' + 1 < p) {
	printf("%ca\n", str[0]+1);
	str[0] += 1;
	ok = true;
      }
    }
    if(!ok) {
      printf("NO\n");
    }
  } else {
    // n >= 3
    bool ok = false;
    for(int i = n - 1; i > 1; i--) {
      int add = 1;
      while(str[i] + add - 'a' + 1 <= p) {
	if(str[i]+add != str[i-1] && str[i]+add != str[i-2]) {
	  for(int k = 0; k < i; k++) {
	    printf("%c", str[k]);
	  }
	  printf("%c", str[i] + add);
	  str[i] += add;
	  for(int k = i + 1; k < n; k++) {
	    for(char print = 'a'; print <= 'a' + p - 1; print++) {
	      if(print != str[k-1] && print != str[k-2]) {
		str[k] = print;
		printf("%c", print);
		break;
	      }
	    }
	  }
	  printf("\n");
	  ok = true;
	  break;
	}
	add++;
      }
      if(ok)
	break;
    }
    if(!ok) {
      int add = 1;
      while(str[1] + add - 'a' + 1 <= p) {
	if(str[1]+add != str[0]) {
	  printf("%c%c", str[0], str[1] + add);
	  str[1] += add;
	  for(int k = 2; k < n; k++) {
	    for(char print = 'a'; print <= 'a' + p -1; print++) {
	      if(print != str[k-1] && print != str[k-2]) {
		printf("%c", print);
		str[k] = print;
		break;
	      }
	    }
	  }
	  printf("\n");
	  ok = true;
	  break;
	}
	add++;
      }
      if(!ok) {
	if(str[0] - 'a' + 1 < p) {
	  printf("%c", str[0]+1);
	  str[0] += 1;
	  for(int k = 1; k < n; k++) {
	    for(char print = 'a'; print <=  'a' + p - 1; print++) {
	      if(print != str[k-1] && print != str[k-2]) {
		printf("%c", print);
		str[k] = print;
		break;
	      }
	    }
	  }
	  printf("\n");
	  ok = true;
	}
      }
    }
    if(!ok)
      printf("NO\n");
  }
  return 0;
}
