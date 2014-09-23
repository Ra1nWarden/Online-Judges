#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    Point(int a, int b, int index) : x(a), y(b), i(index) {};
    int x, y, i;
    int operator-(const Point& another) {
        return abs(x - another.x) + abs(y - another.y);
    };
    bool operator<(const Point& another) const {
       return i < another.i; 
    };
};

int findShortest(vector<Point> points, int startx, int starty) {
    int result = 0;
    for (int i = 1; i < points.size(); i++) {
        result += (points[i] - points[i-1]);
    }
    Point b(startx, starty, -1);  
    result += (points[0] - b);
    result += (b - points.back());
    return result;
}

int main() {
    int cases;
    cin >> cases;
    for (int i= 0;i < cases; i++) {
        int x, y, startx, starty, n;
        cin >> x >> y >> startx >> starty >> n;
        vector<Point> points;
        for (int j = 0; j < n; j++) {
            int nextx, nexty;
            cin >> nextx >> nexty;
            points.push_back(Point(nextx, nexty, j)); 
        }
        int shortest = findShortest(points, startx, starty);
        while(next_permutation(points.begin(), points.end())) {
            int nextResult = findShortest(points, startx, starty);
            if (nextResult < shortest) {
                shortest = nextResult;
            }
        }
        cout << "The shortest path has length " << shortest << endl;
    }
    return 0;
}
