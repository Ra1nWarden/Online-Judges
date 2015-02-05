#include <cstdio>
#include <algorithm>

using namespace std;

struct Job {
    int b, j;
    Job() {};
    Job(int _b, int _j) : b(_b), j(_j) {};
    bool operator<(const Job& rhs) const {
        return j > rhs.j;
    };
};

Job jobs[1001];

int main() {
    int n;
    int tc = 1;
    while(scanf("%d", &n) != EOF && n) {
    
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &jobs[i].b, &jobs[i].j);
        }
        sort(jobs, jobs+n);
        int time = 0;
        int result = 0;
        for(int i = 0; i < n; i++) {
            time += jobs[i].b;
            result = max(result, time + jobs[i].j);
        }
        printf("Case %d: %d\n", tc++, result); 
    }
    return 0;
}

