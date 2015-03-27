#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#define MAXN 1000000000
#define MOD 1000000007

using namespace std;

// @begin_lib
// @end_lib

typedef pair<int, char> Node;

bool _cmp(const Node& a, const Node& b) {
  return a.first < b.first;
}

class TaroFillingAStringDiv1 {
public:
  int getNumber(int N, vector <int> position, string value) {
    vector<Node> nodes;
    for(int i = 0; i < position.size(); i++) {
      nodes.push_back(make_pair(position[i], value[i]));
    }
    sort(nodes.begin(), nodes.end(), _cmp);
    long long result = 1;
    for(int i = 0; i < nodes.size() - 1; i++) {
      int gap = nodes[i+1].first - nodes[i].first - 1;
      bool same = nodes[i].second == nodes[i+1].second;
      if(gap > 0) {
        if(gap % 2 == 0) {
	  if(same) {
	    result *= (gap + 1);
	  } else {
	    result *= 1;
	  }
	} else {
	  if(same) {
	    result *= 1;
	  } else {
	    result *= (gap + 1);
	  }
	}
      }
      result %= MOD;
    }
    return result;
  }
};

// @begin_tests
void _run_test(int N, vector< int > position, string value, int res_expected, int test_no) {
int tc_res = (new TaroFillingAStringDiv1)->getNumber(N, position, value);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
}
int main() {
int N;
vector< int > position;
string value;
int res_expected;
N = 3;
{int tmpa[] = {1, 3};
position.assign(tmpa, tmpa + 2);}
value = "AB";
res_expected = 2;
_run_test(N, position, value, res_expected, 0);
N = 4;
{int tmpa[] = {2, 1, 3, 4};
position.assign(tmpa, tmpa + 4);}
value = "ABBA";
res_expected = 1;
_run_test(N, position, value, res_expected, 1);
N = 25;
{int tmpa[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13};
position.assign(tmpa, tmpa + 15);}
value = "ABBBBABABBAAABA";
res_expected = 1;
_run_test(N, position, value, res_expected, 2);
N = 305;
{int tmpa[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246};
position.assign(tmpa, tmpa + 28);}
value = "ABAABBABBAABABBBBAAAABBABBBA";
res_expected = 43068480;
_run_test(N, position, value, res_expected, 3);
}
// @end_tests

// Born in Emacs
