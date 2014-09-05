#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int>& result) {
    for (int i = 1; i < result.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (abs(i - j) == abs(result[i] - result[j]))
                return false;
        }    
    }    
    return true;
}

int main() {
    int cases;
    cin >> cases;
    vector<int> result;
    for (int i = 0; i < 8; i++) {
        result.push_back(i+1);    
    }
    vector<vector<int> > allperms;
    while(next_permutation(result.begin(), result.end())) {
        if (check(result)) {
            allperms.push_back(result);
        }
    }
    for (int i = 0; i < cases; i++) {
        if (i != 0)
            cout << endl;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl;
        cout << endl;
        int lineCount = 1;
        int x, y;
        cin >> y >> x;
        for (vector<vector<int> >::iterator itr = allperms.begin(); itr != allperms.end(); itr++) {
            if ((*itr)[x-1] == y) {
                printf("%2d      %d %d %d %d %d %d %d %d\n", lineCount++, (*itr)[0], (*itr)[1], (*itr)[2], (*itr)[3],
                (*itr)[4], (*itr)[5], (*itr)[6], (*itr)[7]);
            }    
        }
    }
    return 0;        
}
