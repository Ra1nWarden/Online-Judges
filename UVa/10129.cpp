#include <cstdio>
#include <stack>
#include <cstring>
#define MAXL 10005

using namespace std;

char str[MAXL];
int indegree[26];
int outdegree[26];
bool adjMat[26][26];
bool visited[26];
bool appeared[26];

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    memset(adjMat, false, sizeof adjMat);
    memset(indegree, 0, sizeof indegree);
    memset(outdegree, 0, sizeof outdegree);
    memset(appeared, false, sizeof appeared);
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      scanf("%s\n", str);
      outdegree[str[0] - 'a']++;
      indegree[str[strlen(str) - 1] - 'a']++;
      adjMat[str[0] - 'a'][str[strlen(str) - 1] - 'a'] = adjMat[str[strlen(str) - 1] - 'a'][str[0] - 'a'] = true;
      appeared[str[0] - 'a'] = appeared[str[strlen(str) - 1] - 'a'] = true;
    }
    memset(visited, false, sizeof visited);
    int cc = 0;
    for(int i = 0; i < 26; i++) {
      if(!appeared[i])
	continue;
      if(!visited[i]) {
	cc++;
	stack<int> s;
	s.push(i);
	visited[i] = true;
	while(!s.empty()) {
	  int next = s.top();
	  s.pop();
	  for(int j = 0; j < 26; j++) {
	    if(adjMat[next][j] && !visited[j]) {
	      visited[j] = true;
	      s.push(j);
	    }
	  }
	}
      }
    }
    if(cc > 1) {
      printf("The door cannot be opened.\n");
      continue;
    }

    bool ok = true;
    int enter = false;
    int exit = false;
    for(int i = 0; i < 26; i++) {
      if(indegree[i] != outdegree[i]) {
	if(indegree[i] > outdegree[i]) {
	  if(indegree[i] == outdegree[i] + 1) {
	    if(enter) {
	      ok = false;
	    } else {
	      enter = true;
	    }
	  } else {
	    ok = false;
	  }
	} else {
	  if(outdegree[i] == indegree[i] + 1) {
	    if(exit) {
	      ok = false;
	    } else {
	      exit = true;
	    }
	  } else {
	    ok = false;
	  }
	}
      }
    }
    if(ok)
      printf("Ordering is possible.\n");
    else
      printf("The door cannot be opened.\n");
  }
  return 0;
}
