#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

void process(vector<map<char, char> >& city) {
    int minChange = -1;
    int minIndex = -1;
    for (int i = 0; i < city.size(); i++) {
       map<char, char> base = city[i]; 
       int thisChange = 0;
       for (int j = 0; j < city.size(); j++) {
            if (j == i)
                continue;
            map<char, char> compare = city[j];
            for (map<char, char>::iterator itr = base.begin(); itr != base.end(); itr++) {
                if (compare[itr->first] != itr->second) {
                    thisChange++;    
                }    
            }
       }
       if (minChange == -1) {
            minChange = thisChange;
            minIndex = i+1;
       } else if (thisChange < minChange) {
            minChange = thisChange;
            minIndex = i+1;
       }
    }    
    cout << minIndex << endl;
}

int main() {
    vector<map<char, char> > city;
    while(true) {
        string line;
        getline(cin, line);
        if (line[0] == 'e') {
            process(city);
            city.clear();
        }
        else if (line[0] == '#')
            break;
        else {
            istringstream iss(line);
            map<char, char> eachEntry;
            string each;
            while(getline(iss, each, ',')) {
                eachEntry[each[0]] = each[2];   
            }
            city.push_back(eachEntry);
        }
        
    }
    return 0;    
}
