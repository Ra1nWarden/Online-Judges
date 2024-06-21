#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2e5;
int v[maxn+5];
int n;

void fill(int start, int end, int num, bool forward) {
    bool div = num != 1;
    for(int i = forward ? start : end - 1; forward ? i < end : i >= start; forward ? i++ : i--) {
        if(div) {
            v[i] = v[forward ? i-1 : i+1] >> 1;
        } else {
            v[i] = v[forward ? i-1 : i+1] << 1 | 1;
        }
        div = !div;
    }
}

vector<bool> convert(int num) {
    vector<bool> ans;
    while(num) {
        ans.push_back(num & 1);
        num >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int sub_vector(const vector<bool>& v1, const vector<bool>& v2) {
    for(int i = 0; i < v1.size(); i++) {
        if(i >= v2.size() || v1[i] != v2[i])
            return i;
    }
    return v1.size();
}

void print(bool ok) {
    if(!ok)
        printf("-1\n");
    else {
        for(int i = 0; i < n; i++) {
            if(i)
                printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        vector<int> filled;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            if(v[i] != -1)
                filled.push_back(i);
        }
        
        if(filled.empty()) {
            for(int i = 0; i < n; i++) {
                v[i] = (i & 1) ? 1 : 2;
            }
            print(true);
            continue;
        }

        bool ok = true;
        for(int i = 0; i < filled.size(); i++) {
            //printf("i=%d\n", i);
            int idx = filled[i];
            if(i == 0) {
                fill(0, idx, v[filled[i]], false);
            }
            if(i == filled.size() - 1) {
                fill(filled[i] + 1, n, v[filled[i]], true);
                continue;
            }
            vector<bool> cur_bits = convert(v[filled[i]]);
            vector<bool> next_bits = convert(v[filled[i+1]]);
            
            for(int ii = filled[i] + 1; ii < filled[i+1]; ii++) {
                //printf("ii=%d\n", ii);
                if(cur_bits.size() > next_bits.size()) {
                    //printf("large\n");
                    cur_bits.pop_back();
                    v[ii] = v[ii-1] >> 1;
                } else if(cur_bits.size() < next_bits.size()) {
                    int prefix = sub_vector(cur_bits, next_bits);
                    //printf("small\n");
                    if(prefix < cur_bits.size()) {
                        cur_bits.pop_back();
                        v[ii] = v[ii-1] >> 1;
                    } else {
                        cur_bits.push_back(next_bits[prefix]);
                        if(next_bits[prefix]) {
                            v[ii] = (v[ii-1] << 1) | 1;
                        } else {
                            v[ii] = v[ii-1] << 1;
                        }
                    }
                } else {
                    //printf("same\n");
                    if(cur_bits.size() > 1) {
                        cur_bits.pop_back();
                        v[ii] = v[ii-1] >> 1;
                    } else {
                        cur_bits.push_back(0);
                        v[ii] = v[ii-1] << 1;
                    }
                }
            }

            int last = v[filled[i+1] - 1];
            int last_next = v[filled[i+1]];
            ok = (last / 2 == last_next) || (last == last_next / 2);
            if(!ok)
                break;
        }
        print(ok);
    }
    return 0;
}