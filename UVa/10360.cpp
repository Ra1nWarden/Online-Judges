#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int killed[1026][1026];
        memset(killed, 0, sizeof killed); 
        int d, n;
        cin >> d >> n;
        int max = 0;
        int maxx = -1;
        int maxy = -1;
        for (int j = 0; j < n; j++) {
            int x, y, rats;
            cin >> x >> y >> rats;
            for (int k = x - d; k <= x + d && k <= 1025; k++) {
                if (k < 1)
                    continue;
                for (int l = y - d; l <= y + d && l <= 1025; l++) {
                    if (l < 1)
                        continue;
                    killed[k][l] += rats;    
                    if (killed[k][l] > max) {
                        max = killed[k][l];
                        maxx = k;
                        maxy = l;
                    }
                }    
            }
        }
        cout << maxx << " " << maxy << " " << max << endl;
    }
    return 0;    
}
