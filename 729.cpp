#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream& operator<<(ostream& oss, const vector<int>& bits) {
    for (int i = 0;i < bits.size(); i++)
            oss << bits[i];
    return oss;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        if (i != 0)
            cout << endl;
        vector<int> bits;
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m-n; i++)
            bits.push_back(0);
        for (int i = 0 ; i < n; i++)
            bits.push_back(1);
        cout << bits << endl;
        while(next_permutation(bits.begin(), bits.end()))
                cout << bits << endl;
    }
    return 0;
}
