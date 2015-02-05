#include <iostream>
#include <set>
#include <cstring>

using namespace std;

bool checkNumber(int number) {
    if (number >= 100000 || number < 1000)
            return false;
    bool slots[10];
    memset(slots, 0, 10);
    while(number != 0) {
        if (slots[number % 10])
                return false;
        slots[number % 10] = true;
        number /= 10;
    }
    return true;
}

bool checkValid(int a, int b) {
    bool slots[10];
    memset(slots, 0, 10);
    while(a != 0) {
        if (slots[a % 10]) 
                return false;
        slots[a % 10] = true;
        a /= 10;
    }
    while(b != 0) {
        if (slots[b % 10]) 
                return false;
        slots[b % 10] = true;
        b /= 10;
    }
    for (int i = 1; i < 10; i++) {
        if (!slots[i])
                return false;
    }
    return true;
}

int main() {
    set<int> numbers;
    for (int i = 1234; i <= 98765; i++) {
        if (checkNumber(i))
                numbers.insert(i);
    }
    int mult;
    bool start = true;
    while(cin >> mult && mult) {
           if (!start) {
                cout << endl;        
           } 
           bool found = false;
           for (set<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
                int product = (*itr) * mult;
                if (numbers.count(product) == 1 && checkValid(*itr, product)) {
                        found = true;
                        cout << product << (*itr >= 10000 ? " / " : " / 0") << *itr << " = " << mult << endl;
                }
           } 
           if (!found)
                   cout << "There are no solutions for " << mult << "." << endl;
           start = false;
    }
    return 0;
}
