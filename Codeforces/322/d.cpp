#include <cstdio>
#include <algorithm>

using namespace std;

struct Rect {
  char label;
  int length, width;
  Rect() {}
  Rect(int l, int w, char com) : length(l), width(w), label(com) {}
  bool operator<(const Rect& rhs) const {
    return length > rhs.length;
  }
};


int main() {
  int x1, y1, x2, y2, x3, y3;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  if(x1 < y1)
    swap(x1, y1);
  if(x2 < y2)
    swap(x2, y2);
  if(x3 < y3)
    swap(x3, y3);
  int total = x1 * y1 + x2 * y2 + x3 * y3;
  int side;
  for(side = 0; side * side < total; side++) {}
  if(side * side != total) {
    printf("-1\n");
  } else {
    Rect rects[3];
    rects[0] = Rect(x1, y1, 'A');
    rects[1] = Rect(x2, y2, 'B');
    rects[2] = Rect(x3, y3, 'C');
    sort(rects, rects + 3);
    char output[side][side];
    if(rects[0].length != side) {
      printf("-1\n");
    } else {
      for(int i = 0; i < rects[0].width; i++) {
	for(int j = 0; j < side; j++) {
	  output[i][j] = rects[0].label;
	}
      }
      if(rects[1].length == side && rects[2].length == side) {
	printf("%d\n", side);
	for(int i = rects[0].width; i < rects[0].width + rects[1].width; i++) {
	  for(int j = 0; j < side; j++) {
	    output[i][j] = rects[1].label;
	  }
	}
	for(int i = rects[0].width + rects[1].width; i < side; i++) {
	  for(int j = 0; j < side; j++) {
	    output[i][j] = rects[2].label;
	  }
	}
	for(int i = 0; i < side; i++) {
	  for(int j = 0; j < side; j++) {
	    printf("%c", output[i][j]);
	  }
	  printf("\n");
	}
      } else if(rects[1].length == rects[2].length && rects[1].width + rects[2].width == side) {
	printf("%d\n", side);
	for(int i = rects[0].width; i < side; i++) {
	  for(int j = 0; j < rects[1].width; j++) {
	    output[i][j] = rects[1].label;
	  }
	}
	for(int i = rects[0].width; i < side; i++) {
	  for(int j = rects[1].width; j < side; j++) {
	    output[i][j] = rects[2].label;
	  }
	}
	for(int i = 0; i < side; i++) {
	  for(int j = 0; j < side; j++) {
	    printf("%c", output[i][j]);
	  }
	  printf("\n");
	}
      } else if(rects[1].width == rects[2].length && rects[1].length + rects[2].width == side) {
	printf("%d\n", side);
	for(int i = rects[0].width; i < side; i++) {
	  for(int j = 0; j < rects[1].length; j++) {
	    output[i][j] = rects[1].label;
	  }
	}
	for(int i = rects[0].width; i < side; i++) {
	  for(int j = rects[1].length; j < side; j++) {
	    output[i][j] = rects[2].label;
	  }
	}
	for(int i = 0; i < side; i++) {
	  for(int j = 0; j < side; j++) {
	    printf("%c", output[i][j]);
	  }
	  printf("\n");
	}
      } else if(rects[1].width == rects[2].width && rects[1].length + rects[2].length == side) {
	printf("%d\n", side);
	for(int i = rects[0].width; i < side; i++) {
	  for(int j = 0; j < rects[1].length; j++) {
	    output[i][j] = rects[1].label;
	  }
	}
	for(int i = rects[0].width; i < side; i++) {
	  for(int j = rects[1].length; j < side; j++) {
	    output[i][j] = rects[2].label;
	  }
	}
	for(int i = 0; i < side; i++) {
	  for(int j = 0; j < side; j++) {
	    printf("%c", output[i][j]);
	  }
	  printf("\n");
	}
      } else {
	printf("-1\n");
      }
    }
  }
  return 0;
}
