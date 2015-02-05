#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

struct Node {
    Node() {};
    Node(int a, int b, int index1, int index2) : min(a), max(b), parent(NULL), left(NULL), right(NULL), startIndex(index1), endIndex(index2) {};
    int min, max;
    int startIndex, endIndex;
    Node* parent;
    Node* left;
    Node* right;
};

Node nodes[501][501];
// Tree for columns
Node* trees[501];

Node* combineNodes(Node* leftTree, Node* rightTree) {
    int newMin = leftTree->min < rightTree->min ? leftTree->min : rightTree->min;
    int newMax = leftTree->max > rightTree->max ? leftTree->max : rightTree->max;
    int newStart = leftTree->startIndex;
    int newEnd = rightTree->endIndex;
    Node* result = new Node(newMin, newMax, newStart, newEnd);
    return result;
}


Node* build_tree(int column, int rowStart, int rowEnd) {
        if (rowStart == rowEnd) {
            return &nodes[rowStart][column];
        }
        else {
            Node* leftTree = build_tree(column, rowStart, (rowStart+rowEnd) / 2);
            Node* rightTree = build_tree(column, (rowStart+rowEnd) / 2 + 1, rowEnd);
            Node* result = combineNodes(leftTree, rightTree);
            leftTree->parent = result;
            rightTree->parent = result;
            result->left = leftTree;
            result->right = rightTree;
            return result;
        }
}

void build_trees(int a, int b) {
   for(int i = 1; i <= b; i++) {
        Node* result = build_tree(i, 1, a);
        trees[i] = result;
   } 
}

pair<int, int> query_tree(Node* root, int start, int end) {
        if (root->startIndex == start && root->endIndex == end) {
            pair<int, int> result;
            result.first = root->min;
            result.second = root->max;
            return result;
        }
        if (root->left->endIndex >= end) {
            return query_tree(root->left, start, end);
        } else if (root->right->startIndex <= start) {
            return query_tree(root->right, start, end);
        } else {
            pair<int, int> leftResult = query_tree(root->left, start, root->left->endIndex);
            pair<int, int> rightResult = query_tree(root->right, root->right->startIndex, end);
            pair<int, int> result;
            result.first = leftResult.first < rightResult.first ? leftResult.first : rightResult.first;
            result.second = leftResult.second > rightResult.second ? leftResult.second : rightResult.second;
            return result;
        }

}


void query(int a1, int b1, int a2, int b2) {
        int resultMin, resultMax;
        for (int column = b1; column <= b2; column++) {
           pair<int, int> eachCol = query_tree(trees[column], a1, a2);
           if (column == b1) {
                resultMin = eachCol.first;
                resultMax = eachCol.second;
           } else {
                if (eachCol.first < resultMin)
                        resultMin = eachCol.first;
                if (eachCol.second > resultMax)
                        resultMax = eachCol.second;
           }
        }
        cout << resultMax << " " << resultMin << endl;
}

void change(int a1, int b1, int change, int a) {
    nodes[a1][b1].min = change;
    nodes[a1][b1].max = change;
    trees[b1] = build_tree(b1, 1, a);
}

int main() {
    int a, b;
    while(cin >> a >> b) {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    int number;
                    cin >> number;
                    nodes[i][j] = Node(number, number, i, i);
                }
            }
            build_trees(a, b);
            int o;
            cin >> o >> ws;
            for (int i = 0; i < o; i++) {
                string line;
                getline(cin, line);
                istringstream iss(line.c_str());
                string operation;
                iss >> operation;
                if (operation == "q") {
                    int a1, b1, a2, b2;
                    iss >> a1 >> b1 >> a2 >> b2;
                    query(a1, b1, a2, b2);
                }
                if (operation == "c") {
                    int a1, b1, amount;
                    iss >> a1 >> b1 >> amount;
                    change(a1, b1, amount, a); 
                }
            }
        
    }
    return 0;

}
