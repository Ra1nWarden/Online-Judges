#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int arr[402];

void makeSet(int n) {
    for (int i = 0; i <= 2*n; i++) {
        arr[i] = i;
    }
}

int findSet(int n) {
    return (n == arr[n]) ? n : arr[n] = findSet(arr[n]);
}

void makeEnemy(int a, int b, int people) {
    arr[findSet(a + people)] = findSet(b);
    arr[findSet(b + people)] = findSet(a);
    arr[findSet(a)] = findSet(b + people);
    arr[findSet(b)] = findSet(a + people);
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int total;
        cin >> total;
        makeSet(total);
        for (int j = 1; j <= total; j++) {
            int enemyCount;
            cin >> enemyCount;
            for (int k = 0; k < enemyCount; k++) {
                int enemy;
                cin >> enemy;
                makeEnemy(j, enemy, total);
            }
        }
        map<int, int> countMap;
        int extra = 0;
        for (int j = 1; j <= total * 2; j++) {
            int root = findSet(j);
            cout << "root for index " << j << " is " << root << endl;
            if (root == j)
                    extra++;
            else if (root <= total) {
                if (countMap.count(root) == 0) {
                    countMap[root] = 1;
                } else {
                    countMap[root] = countMap[root] + 1;
                }
            }
        }
        int max = 0;
        for (map<int, int>::iterator itr = countMap.begin(); itr != countMap.end(); itr++) {
            cout << "printing each iterator: " << itr->first << " has " << itr->second << endl;
            if (itr->second > max)
                    max = itr->second;
        }
        cout << max + extra << endl;
    }
    return 0;
}
