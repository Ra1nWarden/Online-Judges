#include <iostream>
#include <set>

using namespace std;

int students[50002];

void makeSet(int n) {
    for (int i = 0; i <=n ; i++) {
        students[i] = i;
    }
}

int findSet(int n) {
    return n == students[n] ? n : (students[n] = findSet(students[n]));
}

void unionSet(int a, int b) {
    students[findSet(a)] = findSet(b);
}

int main() {
    int cases = 1;
    int people, lines;
    while(cin >> people >> lines){
        if (people == 0 && lines == 0) {
            break;
        }
        makeSet(people);
        for (int i = 0; i < lines; i++) {
            int a, b;
            cin >> a >> b;
            unionSet(a, b);
        }
        set<int> sets;
        for (int i = 1; i <= people; i++) {
            int root = findSet(i);
            sets.insert(root);
        }
        cout << "Case " << cases << ": " << sets.size() << endl;
        cases++;
    }
    return 0;
}
