#include <cstdio>
#include <vector>
#include <stack>
#define MAXN 60

using namespace std;

char cards[MAXN][3];
stack<int> piles[MAXN];

bool match(int i, int j) {
  return cards[piles[i].top()][0] == cards[piles[j].top()][0] || cards[piles[i].top()][1] == cards[piles[j].top()][1];
}

int main() {
  while(true) {
    bool end = false;
    for(int i = 0; i < 52; i++) {
      scanf("%s", cards[i]);
      if(i == 0 && cards[0][0] == '#') {
	end = true;
	break;
      }
      while(!piles[i].empty()) {
	piles[i].pop();
      }
      piles[i].push(i);
    }
    if(end)
      break;
    while(true) {
      bool swapped = false;
      for(int i = 0; i < 52; i++) {
	if(!piles[i].empty()) {
	  int u = piles[i].top();
	  //printf("checking %s: \n", cards[u]);
	  int icpy = i;
	  for(int j = 0; j < 3; j++) {
	    icpy--;
	    while(icpy > -1 && piles[icpy].empty()) {
	      icpy--;
	    }
	  }
	  // if(icpy > -1) {
	  //   printf(" against %s (3 steps)\n", cards[piles[icpy].top()]);
	  // }
	  if(icpy > -1 && match(i, icpy)) {
	    int card = piles[i].top();
	    piles[i].pop();
	    piles[icpy].push(card);
	    swapped = true;
	    break;
	  }
	  icpy = i-1;
	  while(icpy > -1 && piles[icpy].empty()) {
	    icpy--;
	  }
	  // if(icpy > -1) {
	  //   printf(" against %s (1 step)\n", cards[piles[icpy].top()]);
	  // }
	  if(icpy > -1 && match(i, icpy)) {
	    //printf(" with 1 step %s\n", cards[icpy]);
	    int card = piles[i].top();
	    piles[i].pop();
	    piles[icpy].push(card);
	    swapped = true;
	    break;
	  }
	}
      }
      if(!swapped)
	break;
      // printf("after each step:");
      // for(int i = 0; i < 52; i++) {
      // 	if(!piles[i].empty())
      // 	  printf(" %s", cards[piles[i].top()]);
      // }
      // printf("\n");
    }
    vector<int> ans;
    for(int i = 0; i < 52; i++) {
      if(!piles[i].empty()) {
	ans.push_back(piles[i].size());
      }
    }
    if(ans.size() == 1) {
      printf("1 pile remaining: 52\n");
    } else {
      printf("%d piles remaining:", ans.size());
      for(int i = 0; i < ans.size(); i++) {
	printf(" %d", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
