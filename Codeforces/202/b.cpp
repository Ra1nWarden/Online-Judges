#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct II {
    int c;
    int v;
    bool operator<(const II& rhs) const {
        if(c != rhs.c) {
            return c < rhs.c;
        }
        return v > rhs.v;
    }
};

II colors[9];
int cv[10];

int main() {
    int v;
    scanf("%d", &v);
    for(int i = 1; i <= 9; i++) {
        colors[i-1].v = i;
        scanf("%d", &colors[i-1].c);
        cv[i] = colors[i-1].c;     
    }
    sort(colors, colors+9);
    bool ok = false;
    while(true) {
        if(v < colors[0].c)
            break;
        int len = v / colors[0].c;
        for(int dig = 9; dig > 0; dig--) {
            if(v < cv[dig])
                continue;
            int vv = v - cv[dig];
            if(vv / colors[0].c == len - 1) {
                printf("%d", dig);
                v = vv;
                ok = true;
                break;
            }
        }
    }
    if(!ok) {
        printf("-1");
    }
    printf("\n");
    return 0;
}