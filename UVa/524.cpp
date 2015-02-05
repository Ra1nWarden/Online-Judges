#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

struct Number {
    Number() {};
    Number(int a) : number(a) {};
    int number;
    vector<int> combi;
};

bool prime[32];
Number numbers[17];
bool used[17];

void init() {
    memset(used, 0, sizeof used);
    memset(prime, 0, sizeof prime);
    prime[2] = true;
    prime[3] = true;
    prime[5] = true;
    prime[7] = true;
    prime[11] = true;
    prime[13] = true;
    prime[17] = true;
    prime[19] = true;
    prime[23] = true;
    prime[29] = true;
    prime[31] = true;
    for (int i = 1; i <= 16; i++) {
        Number number(i);
        for (int j = i +1; j <= 32; j++) {
            if (prime[j] && j - i <= 16) {
                number.combi.push_back(j - i);
            }
        }
        numbers[i] = number;
    }
}

void findRing(vector<int> sequence, bool used[], int size) {
    vector<int> neighbors = numbers[sequence.back()].combi;
    if (sequence.size() == size - 1) {
        int lastOne = -1;
        for (int i = 0; i < neighbors.size(); i++) {
            int nextNumber = neighbors[i];
            if (nextNumber > size)
                continue;
            if (!used[nextNumber]) {
                lastOne = nextNumber; 
                break;
            }    
        }
        if (prime[lastOne + 1]) {
            sequence.push_back(lastOne);
            for (int i = 0; i < sequence.size(); i++) {
                if (i != sequence.size() -1) {
                    cout << sequence[i] << " ";    
                } else {
                    cout << sequence[i] << endl;    
                }  
            }
        }
    } else {
        for (int i = 0; i < neighbors.size(); i++) {
            int nextNumber = neighbors[i];
            if (nextNumber > size)
                continue;
            if (!used[nextNumber]) {
                vector<int> copy(sequence);
                bool copy2[17];
                // we cannot use sizeof used here as used becomes a pointer to array.
                // cout << "sizeof used" << endl; prints 8 byes (64-bit OS)
                memcpy(copy2, used, 17);
                copy2[nextNumber] = true;
                copy.push_back(nextNumber);
                findRing(copy, copy2, size);
            }    
        }    
    }    
}

int main() {
    int number;
    init();
    int cases = 1;
    while(cin >> number) {    
        if (cases != 1) {
            cout << endl;    
        }
        used[1] = true;
        vector<int> sequence;
        sequence.push_back(1);
        cout << "Case " << cases << ":" << endl;
        // At this point, sizeof used returns the actual size as the array used is static (not allocated by malloc/new).
        // cout << "outside used is " << sizeof used << endl;
        findRing(sequence, used, number);
        cases++;
    }
    return 0;    
}
