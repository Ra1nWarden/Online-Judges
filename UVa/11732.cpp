#include <cstdio>
#include <cstring>
#include <vector>
#define MAXL 1005
#define MAXW 4005
#define MAXN 4000005

using namespace std;

char word[MAXL];
char c[MAXN];
int bro[MAXN];
int lchild[MAXN];
int sum[MAXN];
int depth[MAXN];
int val[MAXN];
int node_count;

void insert() {
  int cur = 0;
  int l = strlen(word);
  sum[0]++;
  for(int i = 0; i < l; i++) {
    char nextc = word[i];
    int child = lchild[cur];
    bool found = false;
    while(bro[child] != 0) {
      if(c[child] == nextc) {
	cur = child;
	found = true;
	break;
      }
      child = bro[child];
    }
    if(c[child] == nextc) {
      found = true;
      cur = child;
    }
    if(!found) {
      int newnode;
      if(child != 0) {
	bro[child] = node_count++;
	newnode = bro[child];
      } else {
	lchild[cur] = node_count++;
	newnode = lchild[cur];
      }
      bro[newnode] = 0;
      sum[newnode] = 0;
      depth[newnode] = i+1;
      lchild[newnode] = 0;
      c[newnode] = nextc;
      cur = newnode;
    }
    if(i == l - 1)
      val[cur]++;
    sum[cur]++;
  }
}

long long total() {
  long long res = 0;
  for(int i = 0; i < node_count; i++) {
    res += val[i] > 1 ? val[i]  * (val[i] - 1) * (depth[i] + 1) : 0;
    vector<int> countv;
    if(val[i] > 0)
      countv.push_back(val[i]);
    int child = lchild[i];
    while(child != 0) {
      countv.push_back(sum[child]);
      child = bro[child];
    }
    //printf("countv has size %d\n", countv.size());
    for(int j = 0; j < countv.size(); j++) {
      for(int k = j + 1; k < countv.size(); k++) {
	res += countv[j] * countv[k] * (2 * depth[i] + 1);
      }
    }
  }
  return res;
}

int main() {
  int tc = 1;
  int count;
  while(scanf("%d\n",&count) != EOF && count) {
    memset(val, 0, sizeof val);
    lchild[0] = sum[0] = 0;
    node_count = 1;
    while(count--) {
      scanf("%s\n", word);
      insert();
    }
    printf("Case %d: %lld\n", tc++, total());
  }
  return 0;
}
