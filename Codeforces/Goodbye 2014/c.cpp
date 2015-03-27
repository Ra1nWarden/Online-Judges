#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int v[n];
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int result = 0;
  vector<int> s;
  int b;
  for(int i = 0; i < m; i++) {
    scanf("%d", &b);
    bool found = false;
    for(vector<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
      if(*itr == b) {
	found = true;
	vector<int> news;
	news.push_back(b);
	for(vector<int>::iterator itr2 = s.begin(); itr2 != itr; itr2++) {
	  news.push_back(*itr2);
	}
	for(vector<int>::iterator itr2 = itr+1; itr2 != s.end(); itr2++) {
	  news.push_back(*itr2);
	}
	s = news;
	break;
      } else {
	result += v[*itr - 1];
      }
    }
    if(!found) {
      s.insert(s.begin(), b);
    }
    // cout << "after reading " << b << " result is now " << result << endl;
    // for(int j = 0; j < s.size(); j++) {
    //   cout << s[j] << " ";
    // }
    // cout << endl;
  }
  printf("%d\n", result);
  return 0;
}
