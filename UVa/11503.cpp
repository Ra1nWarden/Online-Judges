#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

string findSet(string key, map<string, string>& peopleMap, map<string, int>& countMap) {
    if (key == peopleMap[key]) {
        return key;
    } else {
        string root = findSet(peopleMap[key], peopleMap, countMap);
        string removed = peopleMap[key];
        countMap[removed] = countMap[removed] - 1;
        countMap[root] = countMap[root] + 1;
        peopleMap[key] = root;
        return root;
    }
}

void unionSet(string key1, string key2, map<string, string>& peopleMap, map<string, int>& countMap) {
    string root1 = findSet(key1, peopleMap, countMap);
    string root2 = findSet(key2, peopleMap, countMap);
    string origRoot = peopleMap[root1];
    countMap[origRoot] = countMap[origRoot] - 1;
    peopleMap[root1] = root2; 
    countMap[root2] = countMap[root2] + 1;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n;
        cin >> n >> ws;
        map<string, string> peopleMap;
        map<string, int> countMap;
        int friends = 0;
        for (int j = 0; j < n; j++) {
           string line;
           getline(cin, line);
           istringstream iss(line.c_str());
           string person1, person2;
           iss >> person1 >> person2;
           if (peopleMap.count(person1) == 0) {
                peopleMap[person1] = person1;
                countMap[person1] = 1;
           }
           string root1 = findSet(person1, peopleMap, countMap);
           if (peopleMap.count(person2) == 0) {
                peopleMap[person2] = person2;
                countMap[person2] = 1;
           }
           string root2 = findSet(person2, peopleMap, countMap); 
           if (root1 != root2) {
                for (map<string, string>::iterator itr = peopleMap.begin(); itr != peopleMap.end(); itr++) {
                    peopleMap[itr->first] = findSet(itr->first, peopleMap, countMap);
                }        
                cout << countMap[root1] + countMap[root2] << endl;
           } else {
                cout << countMap[root1] << endl;
           }
           unionSet(person1, person2, peopleMap, countMap);
        }
    }
    return 0;
}
