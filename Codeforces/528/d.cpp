#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5;
vector<int> adj_mat[maxn+5];
int n, s;

int main() {
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj_mat[u].push_back(v);
        adj_mat[v].push_back(u);
    }
    int leaf = 0;
    for(int i = 1; i <= n; i++) {
        if(adj_mat[i].size() == 1) {
            leaf++;
        }
    }
    printf("%.12lf\n", (s * 1.0) / leaf * 2);
    return 0;
}