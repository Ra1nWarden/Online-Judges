#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node {
    Node(int a, int b, int c) : x(a), y(b), index(c) {};
    int index, x, y;
};

struct Edge {
    Edge(int i1,int i2, double l) : index1(i1), index2(i2), length(l) {};
    int index1, index2;
    double length;
    bool operator<(const Edge& another) const {
        return this->length > another.length;
    }
};

int findSet(int n, int arr[]) {
    return (n == arr[n]) ? n : (arr[n] = findSet(arr[n], arr));
}

void unionSet(int a, int b, int arr[]) {
    int aRoot = findSet(a, arr);
    int bRoot = findSet(b, arr);
    arr[aRoot] = bRoot;
}

bool sameSet(int a, int b, int arr[]) {
    int aRoot = findSet(a, arr);
    int bRoot = findSet(b, arr);
    return aRoot == bRoot;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int s, n;
        cin >> s >> n;
        vector<Node> nodes;
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            nodes.push_back(Node(x, y, j));
        }
        priority_queue<Edge> edges;
        for (int j = 0; j < n - 1; j++) {
            for (int k = j+1; k < n; k++) {
                double length = sqrt(pow(nodes[j].x - nodes[k].x, 2.0) + pow(nodes[j].y - nodes[k].y, 2.0));
                edges.push(Edge(j, k, length));
            }
        }
        bool included[n];
        memset(included, 0, n);
        vector<double> selectedEdges;
        int root[n];
        for (int j = 0; j < n; j++) {
            root[j] = j; 
        }
        while(selectedEdges.size() != n - 1) {
            Edge nextEdge = edges.top();
            edges.pop();
            if (!sameSet(nextEdge.index1, nextEdge.index2, root)) {
                selectedEdges.push_back(nextEdge.length);
                unionSet(nextEdge.index1, nextEdge.index2, root);
                included[nextEdge.index1] = true;
                included[nextEdge.index2] = true;
            }
        }
        printf("%.2f\n", selectedEdges[n - s - 1]);
    }
    return 0;
}
