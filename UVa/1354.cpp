#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXS 7

using namespace std;

typedef pair<double, double> Tree;
double r;
int s;
int weights[MAXS];
bool visited[(1 << MAXS)];
vector<Tree> trees[(1 << MAXS)];
int sum[(1 << MAXS)];

void dfs(int subset) {
  if(visited[subset])
    return;
  visited[subset] = true;
  
  bool children = false;
  for(int i = (subset - 1) & subset; i; i = (i - 1) & subset) {
    children = true;
    int j = subset^i;
    dfs(i);
    dfs(j);
    double l1 = sum[j] * 1.0 / sum[subset];
    double l2 = sum[i] * 1.0 / sum[subset];
    
    for(int ii = 0; ii < trees[i].size(); ii++) {
      for(int jj = 0; jj < trees[j].size(); jj++) {
	Tree tree;
	tree.first = max(trees[i][ii].first + l1, trees[j][jj].first - l2);
	tree.second = max(trees[j][jj].second + l2 , trees[i][ii].second - l1);
	if(tree.first + tree.second < r)
	  trees[subset].push_back(tree);
      }
    }
  }
  if(!children) {
    trees[subset].push_back(make_pair(0, 0));
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%lf %d", &r, &s);
    for(int i = 0; i < s; i++) {
      scanf("%d", &weights[i]);
    }
    
    memset(sum, 0, sizeof sum);
    for(int i = 0; i < (1 << s); i++) {
      trees[i].clear();
      for(int j = 0; j < s; j++) {
	if((i & (1 << j)) != 0) {
	  sum[i] += weights[j];
	}
      }
    }

    memset(visited, false, sizeof visited);
    dfs((1 << s) - 1);
    
    double ans = -1;
    for(int i = 0; i < trees[(1 << s) - 1].size(); i++) {
      ans = max(ans, trees[(1 << s) - 1][i].first + trees[(1 << s) - 1][i].second);
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
