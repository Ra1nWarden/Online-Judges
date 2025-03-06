#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long l, r;
    cin >> l >> r;
    long long ans = 0, a = 0, b = 0;
    for(int i = 62; i >= 0; i--) {
        long long bit = (1LL << i);
        if((bit & r) && !(bit & l)) {
            cout << (bit | (bit - 1)) << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}