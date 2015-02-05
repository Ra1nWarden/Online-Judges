#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y) {
        vector<int> f;
        for (int i = 0; i < x; i++) {
            int number;
            cin >> number;
            f.push_back(number);
        }        
        vector<int> r;
        for (int i =0; i < y; i++) {
            int number;
            cin >> number;
            r.push_back(number);
        }
        vector<double> ratios;
        for (int i = 0; i < x; i++) {
            for (int j = 0;  j < y; j++) {
                int front = f[i];
                int rear = r[j];
                ratios.push_back(((double) rear) / front);
            }    
        }
        sort(ratios.begin(), ratios.end());
        double maxRatio = -1;
        for (int i = 0; i < ratios.size() - 1; i++) {
            double thisResult  = ratios[i+1] / ratios[i];
            if (thisResult > maxRatio)
                maxRatio = thisResult;
        }
        printf("%.2f\n", maxRatio);
    }
    return 0;    
}
