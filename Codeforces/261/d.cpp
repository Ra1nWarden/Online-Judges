#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 1000000;
int v[maxn+5];
int leftv[maxn+5];
int rightv[maxn+5];
int righttree[maxn+5];
int n;

int lowbit(int x) {
    return x & (-x);
}

int sum(int x, int* tree) {
    int ret = 0;
    while(x > 0) {
        ret += tree[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int val, int* tree) {
    while(x < n) {
        tree[x] += val;
        x += lowbit(x);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        if(cnt.count(v[i]))
            cnt[v[i]]++;
        else
            cnt[v[i]] = 1;
        leftv[i] = cnt[v[i]];
    }

    cnt.clear();
    for(int i = n; i >= 1; i--) {
        if(cnt.count(v[i]))
            cnt[v[i]]++;
        else
            cnt[v[i]] = 1;
        rightv[i] = cnt[v[i]];
    }
    
    memset(righttree, 0, sizeof(righttree));
    add(rightv[n], 1, righttree);
    long long ans = 0;
    for(int i = n-1; i >= 1; i--) {
        ans += sum(leftv[i]-1, righttree);
        add(rightv[i], 1, righttree);
    }
    printf("%lld\n", ans);

    return 0;
}