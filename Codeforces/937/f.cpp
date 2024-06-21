#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int a, b, c;

int solve() {
    queue<int> q;
    for(int i = 0; i < c; i++)
        q.push(0);
    if(q.empty())
        return -1;
    for(int i = 0; i < b; i++) {
        int u = q.front();
        q.pop();
        q.push(u + 1);
    }
    for(int i = 0; i < a; i++) {
        if(q.size() < 2)
            return -1;
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        q.push(max(u, v) + 1);
    }
    if(q.size() != 1)
        return -1;
    return q.front();
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", solve());    
    }
    return 0;
}