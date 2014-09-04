#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Node {
    Node() {};
    Node(int a) : index(a), parent(a){};
    int index, parent;
    set<int> neibours;
};

int findSet(int n, map<int, Node>& nodes) {
    if (nodes[n].parent == n)
            return n;
    int result = findSet(nodes[n].parent, nodes);
    Node copied = nodes[n];
    copied.parent = result;
    nodes[n] = copied; 
    return result; 
}

bool countCycle(map<int, Node>& nodes, int total) {
    int common = -1;
    int count = 1;
    for (map<int, Node>::iterator itr = nodes.begin(); itr != nodes.end(); itr++) {
        int next = findSet(itr->second.index, nodes);
        if (common == -1) {
            common = next;
            continue;
        } 
        if (next != common)
                return false;
        else
                count++;
    }
    return count == total;
}

bool unionSet(int a, int b, map<int, Node>& nodes, int total) {
    if (nodes.count(a) == 0) {
        nodes[a] = Node(a);        
    }
    if (nodes.count(b) == 0) {
        nodes[b] = Node(b);        
    }
    if (findSet(a, nodes) == findSet(b, nodes) && nodes[a].neibours.count(b) == 0 && !countCycle(nodes, total)) {
        return false;
    }
    Node copied = nodes[findSet(a, nodes)];
    copied.parent = findSet(b, nodes);
    nodes[findSet(a, nodes)] = copied;
    Node aCopied = nodes[a];
    aCopied.neibours.insert(b);
    nodes[a] = aCopied;
    if (nodes[a].neibours.size() > 2) {
            return false;
    }
    Node bCopied = nodes[b];
    bCopied.neibours.insert(a);
    nodes[b] = bCopied;
    if (nodes[b].neibours.size() > 2) {
            return false;
    }
    return true;
}

int main() {
    int kids, wishes;
    while(cin >> kids >> wishes && (kids || wishes)) {
        bool possible = true;
        map<int, Node> nodes;
        for (int i = 0; i < wishes; i++) {
            int a, b;
            cin >> a >> b;
            if (!possible)
                    continue;
            possible = possible && unionSet(a, b, nodes, kids);
        }
        cout << (possible ? "Y" : "N") << endl;
    }
    return 0;     
}
