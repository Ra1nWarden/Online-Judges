#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxl = 1500;
char str[maxl + 5];
char good[30];
int k, l;
vector<bool> ok;
vector<vector<int> > nodes;

int main() {
    scanf("%s", str);
    scanf("%s", good);
    scanf("%d", &k);
    l = strlen(str);
    ok.push_back(false);
    nodes.emplace_back(26, 0);
    for(int i = 0; i < l; i++) {
        int cur = 0;
        int cnt = 0;
        for(int j = i; j < l; j++) {
            int idx = str[j] - 'a';
            bool is_good = good[idx] == '1';
            int& next_node = nodes[cur][idx];
            if(next_node == 0) {
                nodes.emplace_back(26, 0);
                ok.push_back(false);
                next_node = nodes.size() - 1;
            }
            if(!is_good) {
                cnt++;
            }
            if(cnt > k) {
                break;
            }
            cur = next_node;
            ok[next_node] = true;
        }
    }
    int ans = 0;
    for(int i = 0; i < ok.size(); i++) {
        if(ok[i])
            ans++;
    }
    printf("%d\n", ans);
}