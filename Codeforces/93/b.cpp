#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;
char str[maxn+5];
char ans[maxn+5];
int prefix[maxn+5];
int len;

void prefix_func() {
    len = strlen(str);
    prefix[0] = 0;
    for(int i = 1; i < len; i++) {
        int j = prefix[i-1];
        while(j > 0 && str[i] != str[j]) {
            j = prefix[j - 1];
        }
        if(str[i] == str[j]) {
            j++;
        }
        prefix[i] = j;
    }
}

int main() {
    scanf("%s", str);
    prefix_func();
    bool found = false;
    if(prefix[len - 1] != 0) {
        for(int i = 0; i < len - 1; i++) {
            if(prefix[i] == prefix[len-1]) {
                strncpy(ans, str, prefix[i]);
                ans[prefix[i]] = '\0';
                found = true;
                break;
            }
        }
        if(!found && prefix[prefix[len-1]-1] != 0) {
            strncpy(ans, str, prefix[prefix[len-1]-1]);
            ans[prefix[prefix[len-1]-1]] = '\0';
            found = true;
        }
    }
    if(found) {
        printf("%s\n", ans);
    } else {
        printf("Just a legend\n");
    }
    return 0;
}