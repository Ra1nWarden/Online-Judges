#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    Node() {};
    Node(int number) : index(number), black(false) {};
    int index;
    bool black;
    vector<int> connected;
};

ostream& operator<<(ostream& oss, const Node& node) {
    oss << "index is " << node.index << endl;
    for (int i = 0; i < node.connected.size(); i++) {
        oss << node.connected[i] << " ";        
    }
    oss << endl;
    return oss;
}

vector<int> findMaxBlack(int a, int b, map<int, Node> nodes) {
    if (a > b) {
        vector<int> result;
        for (int i = 1; i <= b; i++) {
            if (nodes[i].black)
                result.push_back(i);
        }    
        return result;
    } 
    else {
        vector<int> neighbors = nodes[a].connected;
        bool blackOk = true;
        for (int i = 0; i < neighbors.size(); i++) {
            if (nodes[neighbors[i]].black) {
                blackOk = false;
                break;
            }
        }    
        if (blackOk) {
            vector<int> white = findMaxBlack(a+1, b, nodes);
            nodes[a].black = true;
            vector<int> black = findMaxBlack(a+1, b, nodes); 
            return white.size() > black.size() ? white : black;
        } else {
            return findMaxBlack(a+1, b, nodes);    
        }
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0 ;i < cases; i++) {
        int vertices, edges;
        cin >> vertices >> edges;
        map<int, Node> nodes;
        for (int j = 1; j <= vertices; j++) {
            nodes[j] = Node(j);    
        }
        for (int j = 0 ; j < edges; j++) {
            int a, b;
            cin >> a >> b;
            nodes[a].connected.push_back(b);
            nodes[b].connected.push_back(a);
        }
        vector<int> result = findMaxBlack(1, vertices, nodes);
        cout << result.size() << endl;
        for (int j = 0; j < result.size(); j++) {
            if (j != result.size() - 1) {
                cout << result[j] << " ";    
            } else {
                cout << result [j] << endl;    
            }
        }
    }
    return 0;   
}
