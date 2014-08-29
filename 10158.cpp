#include <iostream>

using namespace std;

int root[20000];

void makeSet(int number) {
    for (int i = 0; i <= number*2; i++) {
        root[i] = i;
    }
}

int findSet(int x) {
    return (root[x] == x) ? x : (root[x] = findSet(root[x]));
}

void setFriends(int a, int b, int people) {
    int aRoot = findSet(a);
    int bRoot = findSet(b);
    int aEnemyRoot = findSet(a + people);
    int bEnemyRoot = findSet(b + people);
    if (aRoot == bEnemyRoot || bRoot == aEnemyRoot) {
        cout << -1 << endl;
    }
    else {
        root[aRoot] = bRoot;
        root[aEnemyRoot] = bEnemyRoot;
    }
}

void setEnemies(int a, int b, int people) {
    int aRoot = findSet(a);
    int bRoot = findSet(b);
    int aEnemyRoot = findSet(a + people);
    int bEnemyRoot = findSet(b + people);
    if (aRoot == bRoot) {
        cout << -1 << endl;
    } else {
        root[aEnemyRoot] = bRoot;
        root[bEnemyRoot] = aRoot;
    }
}

void areFriends(int a, int b) {
    cout << ((findSet(a) == findSet(b)) ? 1 : 0) << endl;
}

void areEnemies(int a, int b, int people) {
    int aRoot = findSet(a);
    int bRoot = findSet(b);
    int aEnemyRoot = findSet(a + people);
    int bEnemyRoot = findSet(b + people);
    cout << ((aRoot == bEnemyRoot || bRoot == aEnemyRoot) ? 1 : 0) << endl;
}

int main() {
    int total;
    cin >> total;
    makeSet(total);
    int a, b, c;
    while(cin >> a >> b >> c) {
        switch(a) {
            case 1:
                setFriends(b, c, total);                
                break;
            case 2:
                setEnemies(b, c, total);
                break;
            case 3:
                areFriends(b, c);
                break;
            case 4:
                areEnemies(b, c, total);
                break;
            default:
                break;
        }
    }
}
