#include <iostream>
#include <map>

using namespace std;

int arr[500001];

void makeSet(int n) {
    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }
}

int findSet(int n) {
    return n == arr[n] ? n : (arr[n] = findSet(arr[n]));
}

void unionSet(int a, int b) {
    arr[findSet(a)] = findSet(b); 
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n, m;
        cin >> n >> m;
        makeSet(n);
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            unionSet(a, b);
        }
        map<int, int> countMap;
        for (int j = 1; j <= n; j++) {
            int root = findSet(j);
            if (countMap.count(root) == 0) {
                countMap[root] = 1;
            } else {
                countMap[root] = countMap[root] + 1;
            }
        }
        int max = 0;
        for (map<int, int>::iterator itr = countMap.begin(); itr != countMap.end(); itr++) {
            if (itr->second > max) {
                max = itr->second;
            }
        }
        cout << max << endl;
    }
    return 0;
}
