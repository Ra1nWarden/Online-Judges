#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Gas {
    Gas(double a, double b) : dist(a), ppg(b) {};
    double dist, ppg;  
};

struct Car {
    Car(double a, double b) : tank(a), mpg(b) {};
    double tank, mpg;   
};

double findMinCost(int a, int b, const vector<Gas>& stations, double remain, double accum, double total, Car car) {
    if (a == b) {
        return accum;
    } else {
       double travelled = (a == 0 ? stations[a].dist : stations[a].dist - stations[a-1].dist);
       double gasUsed = travelled / car.mpg;
       remain -= gasUsed;
       double nextStop = (a == b-1 ? total - stations[a].dist : stations[a+1].dist - stations[a].dist);
       double nextUsed = nextStop / car.mpg;
       if (nextUsed > remain) {
            // have to fuel up    
            double toBeFueled = car.tank - remain;
            accum += (toBeFueled * stations[a].ppg / 100+ 2.0);
            return findMinCost(a + 1, b, stations, car.tank, accum, total, car);
       } else if (remain > (car.tank / 2)) {
            // will not fuel up    
            return findMinCost(a+1, b, stations, remain, accum, total, car);
       } else {
            // ambiguous case    
            double notFuel = findMinCost(a+1, b, stations, remain, accum, total, car);
            double toBeFueled = car.tank - remain;
            accum += (toBeFueled * stations[a].ppg / 100+ 2.0);
            double fueled = findMinCost(a + 1, b, stations, car.tank, accum, total, car);
            return notFuel < fueled ? notFuel : fueled;
       }
    }    
}

int main() {
    double d;
    int cases = 1;
    while(cin >> d) {
        if (d < 0)
            break;
        double cap, mpg, start;
        cin >> cap >> mpg >> start;
        Car car(cap, mpg);
        int n;
        cin >> n;
        vector<Gas> stations;
        for (int i = 0; i < n; i++) {
            double dist, ppg;
            cin >> dist >> ppg;
            stations.push_back(Gas(dist, ppg));
        }
        double remaining = cap;
        double minCost = findMinCost(0, n, stations, remaining, start, d, car);
        printf("Data Set #%d\n", cases);
        printf("minimum cost = $%.2f\n", minCost);
        cases++;
    }
    return 0;    
}
