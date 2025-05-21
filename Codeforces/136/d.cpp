#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int ansv[maxn+5];
int n, m, block_size;
int cnt[maxn+5];

struct Node {
    int start, end, idx;
    bool operator < (const Node &b) const {
        if(start / block_size != b.start / block_size) {
            return start / block_size < b.start / block_size;
        }
        return end < b.end;
    }
};

Node nodes[maxn+5];

int add(int x, int ans) {
    if(x > maxn)
        return ans;
    int prev = cnt[x];
    cnt[x] = prev + 1;
    if(cnt[x] == x) {
        ans++;
    } else if(prev == x) {
        ans--;
    }
    return ans;
}

int remove(int x, int ans) {
    if(x > maxn)
        return ans;
    int prev = cnt[x];
    cnt[x] = prev - 1;
    if(cnt[x] == x) {
        ans++;
    } else if(prev == x) {
        ans--;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    block_size = sqrt(n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        nodes[i] = {l, r, i};
    }
    sort(nodes, nodes+m);
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    int cur_start = 1, cur_end = 1;
    if(v[1] <= maxn) {
        cnt[v[1]]++;
        if(v[1] == cnt[v[1]])
            ans++;
    }
    for(int i = 0; i < m; i++) {
        int next_start = nodes[i].start, next_end = nodes[i].end;
        while(cur_end < next_end)
            ans = add(v[++cur_end], ans);
        while(cur_start > next_start)
            ans = add(v[--cur_start], ans);
        while(cur_end > next_end)
            ans = remove(v[cur_end--], ans);
        while(cur_start < next_start)
            ans = remove(v[cur_start++], ans);
        ansv[nodes[i].idx] = ans;
    }
    for(int i = 0; i < m; i++) {
        printf("%d\n", ansv[i]);
    }
    return 0;
}