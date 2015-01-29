#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct Pos {
    int dist;
    int index;
    char dir;
    Pos() {};
    Pos(int _dist, char _dir) : dist(_dist), dir(_dir) {};
    bool operator<(const Pos& b) const {
        return dist < b.dist;
    };
};

Pos pos[10001];
Pos result[10001];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int et = 1; et <= tc; et++) {
        int l, t, n;
        scanf("%d %d %d", &l, &t, &n);
       
        char dir;
        for(int i = 0; i < n; i++) {
            scanf("%d %c", &pos[i].dist, &pos[i].dir);
            pos[i].index = i;
        }
        sort(pos, pos+n);
	// cout << "debug: "<< endl;
	// for(int i = 0; i < n; i++) {
	//   cout << pos[i].dist << " " << pos[i].index << " " << pos[i].dir << endl;
	// } 

        for(int i = 0; i < n; i++) {
            result[i].dist = pos[i].dir == 'L' ? pos[i].dist -= t : pos[i].dist += t;
            if(result[i].dist >= 0 && result[i].dist <= l) {
	      result[i].dir = pos[i].dir;
            } else {
	      result[i].dir = 'F';
	    }
        }
	sort(result, result+n);

	int printv[n];
	char printd[n];

	for(int i = 0; i < n; i++) {
	  printv[pos[i].index] = result[i].dist;
	  printd[pos[i].index] = result[i].dir;
	  bool turning = false;
	  if(i > 0)
	    turning = turning || result[i].dist == result[i-1].dist;
	  if(i <  n - 1)
	    turning = turning || result[i].dist == result[i+1].dist;
	  if(turning)
	    printd[pos[i].index] = 'T';
	}

        printf("Case #%d:\n", et);
	for(int i = 0; i < n; i++) {
	  if(printd[i] == 'F') {
	    printf("Fell off\n");
	  } else {
	    printf("%d ", printv[i]);
	    if(printd[i] == 'T')
	      printf("Turning\n");
	    else
	      printf("%c\n", printd[i]);
	  }
	}
	printf("\n");
    }
}
