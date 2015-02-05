#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Item {
    Item(int p, vector<int> r) : price(p), rules(r) {};
    int price;
    vector<int> rules;
};

vector<Item> construct(int size1, int size2) {
        vector<Item> travel;
        for (int i = 0; i < size1; i++) {
            int price;
            cin >> price;
            vector<int> allowed;
            for (int j = 0; j < size2; j++) {
                int yes;
                cin >> yes;
                allowed.push_back(yes);
            }
            travel.push_back(Item(price, allowed));
        }
   return travel; 
}

int main() {
    int t, r, h;
    while(cin >> t >> r >> h) {
        vector<Item> travel = construct(t, r);
        vector<Item> rest = construct(r, h);
        vector<Item> hotel = construct(h, t);
        int tp = -1;
        int rp = -1;
        int hp = -1;
        int minPrice = -1;
        for (int i = 0; i < travel.size(); i++) {
            for (int j = 0; j < rest.size(); j++) {
                if (travel[i].rules[j])
                    continue;
                for (int k = 0; k < hotel.size(); k++) {
                   if (!rest[j].rules[k] && !hotel[k].rules[i]) {
                        int newPrice = (travel[i].price + rest[j].price + hotel[k].price); 
                        if (minPrice == -1 || newPrice < minPrice) {
                            minPrice = newPrice; 
                            tp = i;
                            rp = j;
                            hp = k;
                        }    
                   } 
                }        
            }
        }
        if (minPrice == -1)
            cout << "Don't get married!" << endl;
        else {
            printf("%d %d %d:%d\n", tp, rp, hp, minPrice);    
        }
    }
    return 0;    
}
