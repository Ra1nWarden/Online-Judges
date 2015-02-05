#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    bool start = true;
    while(true) {
        int count;
        cin >> count;
        if (count == 0)
            break;
        if (!start) cout << endl;
        vector<int> numbers;
        for (int i = 0; i < count; i++) {
            int number;
            cin >> number;
            numbers.push_back(number);
        }
        for (int i = 0; i < count; i++) {
            for (int j = i+1; j < count; j++) {
                for (int k = j+1; k < count; k++) {
                    for (int l = k+1; l < count; l++) {
                        for (int m = l+1; m < count; m++) {
                            for (int n = m+1; n < count; n++) {
                                printf("%d %d %d %d %d %d\n", numbers[i], numbers[j], numbers[k], numbers[l],
                                numbers[m], numbers[n]);    
                            }    
                        }    
                    }    
                }    
            }    
        }
        start = false;
    }
    return 0;    
}
