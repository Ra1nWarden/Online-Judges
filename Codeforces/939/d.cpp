#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 18;
int dp[maxn+5][maxn+5];
int cut[maxn+5][maxn+5];
int v[maxn+5];
int n;
typedef pair<int, int> II;

void generate(int i, int j, int num, vector<II>& cuts) {
    //printf("generate(%d, %d, %d)\n", i, j, num);
    if(num == 0)
        return;
    for(int d = 1; num - d >= 0; d++) {
        generate(i, j - d + 1, num - d, cuts);
        if(num - d > 0 && j - d >= i)
            cuts.push_back({i, j - d});
    }
    cuts.push_back({i, j});
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        dp[i][i] = max(1, v[i]);
        cut[i][i] = i;
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int cur_max = len * len;
            cut[i][i+len-1] = i+len-1;
            for(int j = i; j <= i + len - 1; j++) {
                int cur = dp[i][j];
                if(j + 1 <= i + len - 1)
                    cur += dp[j+1][i+len-1];
                if(cur > cur_max) {
                    cur_max = cur;
                    cut[i][i+len-1] = j;
                }
            }
            dp[i][i+len-1] = cur_max;
        }
    }
    //printf("dp done %d\n", dp[0][n-1]);

    vector<II> segments = {make_pair(0, n-1)};

    while(true) {
        vector<II> new_segments;
        bool done = true;
        for(int i = 0; i < segments.size(); i++) {
            II u = segments[i];
            if(cut[u.first][u.second] != u.second) {
                new_segments.push_back({u.first, cut[u.first][u.second]});
                new_segments.push_back({cut[u.first][u.second] + 1, u.second});
                done = false;
            } else {
                new_segments.push_back(u);
            }
        }
        segments = new_segments;
        if(done)
            break;
    }

    // printf("segments done\n");
    // for(int i = 0; i < segments.size(); i++)
    //     printf("[%d, %d] ", segments[i].first, segments[i].second);
    // printf("\n");

    vector<II> cuts;
    for(int i = 0; i < segments.size(); i++) {
        II seg = segments[i];
        if(seg.first == seg.second) {
            if(v[seg.first] == 0)
                cuts.push_back({seg.first, seg.second});
            continue;
        }
        for(int j = seg.first; j <= seg.second; j++) {
            if(v[j] != 0)
                cuts.push_back({j, j});
        }
        //printf("before generate %d %d %d\n", seg.first, seg.second, seg.second - seg.first + 1);
        generate(seg.first, seg.second, seg.second - seg.first + 1, cuts);
    }

    printf("%d %d\n", dp[0][n-1], cuts.size());
    for(int i = 0; i < cuts.size(); i++) {
        printf("%d %d\n", cuts[i].first + 1, cuts[i].second + 1);
    }

    return 0;
}