#include <cstdio>
#include <queue>

using namespace std;

int check_bits(int n, priority_queue<int>& ans) {
    int ret = 0;
    int num = 1;
    while(n) {
        if(n & 1) {
            ret++;
            ans.push(num);
        }
        n >>= 1;
        num <<= 1;
    }
    return ret;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    priority_queue<int> ans;
    if(k > n || check_bits(n, ans) > k) {
        printf("NO\n");
        return 0;
    }
    while(ans.size() < k) {
        int high = ans.top();
        ans.pop();
        ans.push(high / 2);
        ans.push(high / 2);
    }
    printf("YES\n");
    bool start = true;
    while(!ans.empty()) {
        if(!start)
            printf(" ");
        printf("%d", ans.top());
        ans.pop();
        start = false;
    }
    printf("\n");
    return 0;
}