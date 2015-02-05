#include <iostream>

using namespace std;

int findDest(int depth, int index, int root) {
    if (depth == 2) {
        return index == 1 ? root * 2 : (root * 2 +1); 
    } else {
        if (index % 2 == 1) {
            //left`
            return findDest(depth - 1, (index + 1) /2, root * 2);
        } else {
            //right
            return findDest(depth - 1, index / 2, root * 2 + 1);
        }
    }

}

int main() {
    int cases; 
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int d, index;
        cin >> d >> index;
        cout << findDest(d, index, 1) << endl;
    }
    return 0;
}
