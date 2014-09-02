#include <iostream>
#include <vector>

using namespace std;

struct NumberSeg {
    NumberSeg() {};
    NumberSeg(int a, int b) : number(a), length(b) {};
    int number;
    int length;
    bool operator==(const NumberSeg& another) const {
        return another.number == this->number && another.length == this->length;
    };
};

struct Node {
    Node(NumberSeg a, NumberSeg b, int length) : start(a), end(b), maxLength(length), parent(NULL), left(NULL), right(NULL) {};
    int startIndex;
    int endIndex;
    NumberSeg start;
    NumberSeg end;
    int maxLength;
    Node* parent;
    Node* left;
    Node* right;
    bool singleNumberNode() {
        return start.number == end.number;
    };
};

int newMax(Node* leftTree, Node* rightTree) {
    int newMax = leftTree->maxLength > rightTree->maxLength ? leftTree->maxLength : rightTree->maxLength;
    if (leftTree->end.number == rightTree->start.number) {
        int possibleMax = leftTree->end.length + rightTree->start.length;
        if (possibleMax > leftTree->maxLength && possibleMax > rightTree->maxLength) {
            newMax = possibleMax;
        }
    }
    return newMax;
}

Node* combineNodes(Node* leftTree, Node* rightTree) {
        int newLength = newMax(leftTree, rightTree);
        NumberSeg newStart, newEnd;
        if (leftTree->singleNumberNode()) {
            if (rightTree->start.number == leftTree->start.number) {
                newStart = NumberSeg(rightTree->start.number, rightTree->start.length + leftTree->start.length);
            } else {
                newStart = leftTree->start;
            }
        } else {
            newStart = leftTree->start;
        }
        if (rightTree->singleNumberNode()) {
            if (leftTree->end.number == rightTree->start.number) {
                newEnd = NumberSeg(rightTree->start.number, rightTree->start.length + leftTree->end.length);
            } else {
                newEnd = rightTree->end;
            }
        } else {
            newEnd = rightTree->end;
        }
        Node* result = new Node(newStart, newEnd, newLength);
        result->left = leftTree;
        result->right = rightTree;
        result->startIndex = leftTree->startIndex;
        result->endIndex = rightTree->endIndex;
        return result;
}

Node* init_tree(vector<Node>& nodes, int start, int end) {
    if (start == end) {
        return &nodes[start];
    } else {
        Node* leftTree = init_tree(nodes, start, (start+end) / 2);
        Node* rightTree = init_tree(nodes, (start+end) / 2 + 1, end);
        Node* result = combineNodes(leftTree, rightTree);
        leftTree->parent = result;
        rightTree->parent = result;
        return result;
    }
}

Node* findNode(int start, int end, Node* root) {
    if (start == root->startIndex && end == root->endIndex) {
        return root; 
    } else if (end <= root->left->endIndex) {
        return findNode(start, end, root->left);
    } else if (start >= root->right->startIndex) {
        return findNode(start, end, root->right);
    } else {
       Node* left = findNode(start, root->left->endIndex, root->left);
       Node* right = findNode(root->right->startIndex, end, root->right);
       return combineNodes(left, right);
    }
}

int main() {
    int count;
    while(cin >> count && count) {
        int queries;
        cin >> queries;
        vector<Node> nodes;
        for (int i = 1; i <= count; i++) {
            int number;
            cin >> number;
            NumberSeg numSeg(number, 1);
            Node node(numSeg, numSeg, 1);
            node.startIndex = i;
            node.endIndex = i;
            nodes.push_back(node);
        }
        Node* root = init_tree(nodes, 0, nodes.size() - 1);
        for (int i = 0; i < queries; i++) {
            int start, end;
            cin >> start >> end;
            cout << findNode(start, end, root)->maxLength << endl;
        }
    }
    return 0;
}
