#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5;
int v[maxn+5];
int ans[maxn+5];
int n;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        map<int, vector<int> > m;
        map<int, vector<int> > im;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            int base = v[i] >> 2;
            if(m.count(base)) {
                m[base].push_back(v[i]);
                im[base].push_back(i);
            } else {
                m[base] = {v[i]};
                im[base] = {i};
            }
        }
        for(auto each = m.begin(); each != m.end(); each++) {
            sort(each->second.begin(), each->second.end());
            vector<int> indices = im[each->first];
            auto num = each->second.begin();
            for(auto idx : indices) {
                ans[idx] = *num;
                num++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}