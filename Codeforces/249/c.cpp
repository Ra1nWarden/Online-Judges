#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, bool> IB;
vector<IB> v;
int minVal = 0;
int maxVal = 0;

int main() {
  int n;
  scanf("%d", &n);
  int pos = 0;
  int up = true;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    for(int j = 0; j < num; j++) {
      v.push_back(make_pair(pos, up));
      if(j != num - 1) {
	if(up)
	  pos++;
	else
	  pos--;
      }
      minVal = min(minVal, pos);
      maxVal = max(maxVal, pos);
    }
    up = !up;
  }
  for(int i = maxVal - minVal; i >= 0; i--) {
    for(int j = 0; j < v.size(); j++) {
      if(v[j].first - minVal == i) {
	if(v[j].second)
	  printf("/");
	else
	  printf("\\");
      } else
	printf(" ");
    }
    printf("\n");
  }
  return 0;
}
