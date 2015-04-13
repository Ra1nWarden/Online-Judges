#include <cstdio>
#include <cstring>

using namespace std;

char cube1[7];
char cube2[7];
char str[15];
int left[] = {0, 4, 2, 1, 6, 5, 3};
int down[] = {0, 5, 1, 3, 4, 6, 2};
int hleft[] = {0, 1, 4, 2, 5, 3, 6};
int hright[] = {0, 1, 3, 5, 2, 4, 6};

void turn(int* dv) {
  char rotated[7];
  for(int i = 1; i <= 6; i++) {
    rotated[i] = cube1[dv[i]];
  }
  memcpy(cube1, rotated, sizeof rotated);
}

int main() {
  while(scanf("%s\n", str) != EOF) {
    for(int i = 1; i <= 6; i++)
      cube1[i] = str[i-1];
    for(int i = 1; i <= 6; i++)
      cube2[i] = str[5+i];
    bool found = false;
    for(int i = 0; i < 4; i++) {
      turn(down);
      for(int j = 0; j < 4; j++) {
	turn(left);
	bool ok = true;
	for(int k = 1; k <= 6; k++) {
	  if(cube1[k] != cube2[k]) {
	    ok = false;
	    break;
	  }
	}
	if(ok) {
	  found = true;
	  break;
	}
      }
      if(found)
	break;
    }
    if(!found) {
      turn(hleft);
      for(int i = 0; i < 4; i++) {
	turn(left);
	bool ok = true;
	for(int k = 1; k <= 6; k++) {
	  if(cube1[k] != cube2[k]) {
	    ok = false;
	    break;
	  }
	}
	if(ok) {
	  found = true;
	  break;
	}
      }
      if(!found) {
	turn(hright);
	turn(hright);
	for(int i = 0; i < 4; i++) {
	  turn(left);
	  bool ok = true;
	  for(int k = 1; k <= 6; k++) {
	    if(cube1[k] != cube2[k]) {
	      ok = false;
	      break;
	    }
	  }
	  if(ok) {
	    found = true;
	    break;
	  }
	}
      }
    }
    if(found)
      printf("TRUE\n");
    else
      printf("FALSE\n");
  }
  return 0;
}
