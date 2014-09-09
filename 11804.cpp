#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

struct Player {
    Player(string n, int a, int b) : name(n), attack(a), defend(b) {};
    string name;
    int attack, defend;
    bool operator<(const Player& other) const {
        return name < other.name;
    };
};

int main() {
    int cases;
    cin >> cases >> ws;
    for (int i = 0; i < cases; i++) {
        vector<Player> players;
        for(int j = 0; j < 10; j++) {
            string line;
            getline(cin, line);
            istringstream iss(line.c_str());
            string name;
            int attack, defend;
            iss >> name >> attack >> defend;
            players.push_back(Player(name, attack, defend));
        }                
        sort(players.begin(), players.end());
        int maxAttack = 0;
        int maxDef = 0;
        bool attNumber[10];
        memset(attNumber, 0, sizeof attNumber);
        for (int a = 0; a < 6; a++) {
            for (int b = a+1; b < 7; b++) {
                for (int c = b+1; c < 8; c++) {
                    for (int d = c+1; d < 9; d++) {
                        for (int e = d+1; e < 10; e++) {
                            int combineAttack = 0;
                            int combineDefend = 0;
                            combineAttack += players[a].attack;
                            combineAttack += players[b].attack;
                            combineAttack += players[c].attack;
                            combineAttack += players[d].attack;
                            combineAttack += players[e].attack;
                            for (int x = 0; x < 10; x++) {
                                if (x != a && x != b && x!= c && x != d && x != e) {
                                        combineDefend += players[x].defend;
                                }
                            }
                            if (combineAttack > maxAttack || (combineAttack == maxAttack && combineDefend > maxDef)) {
                                memset(attNumber, 0, sizeof attNumber);
                                maxAttack = combineAttack;
                                maxDef = combineDefend;
                                attNumber[a] = true;
                                attNumber[b] = true;
                                attNumber[c] = true;
                                attNumber[d] = true;
                                attNumber[e] = true;
                            } 
                        }
                    }
                }
            }
        }
        vector<string> attNames;
        vector<string> defNames;
        for (int j = 0; j < 10; j++) {
           if(attNumber[j])
                   attNames.push_back(players[j].name);
           else
                   defNames.push_back(players[j].name);
        }
        printf("Case %d:\n", i+1);
        printf("(%s, %s, %s, %s, %s)\n", attNames[0].c_str(), attNames[1].c_str(), attNames[2].c_str(), attNames[3].c_str(), attNames[4].c_str());
        printf("(%s, %s, %s, %s, %s)\n", defNames[0].c_str(), defNames[1].c_str(), defNames[2].c_str(), defNames[3].c_str(), defNames[4].c_str());
    }
    return 0;    
}
