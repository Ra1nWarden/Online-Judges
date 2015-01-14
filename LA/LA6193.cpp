#include <iostream>
#include <utility>

using namespace std;

int main() {
  int n, m;
  while(cin >> n >> m && (n || m)) {
    int totalcomponent = 0;
    int maxReviewers = 0;
    int totalengineer = 0;
    long long reviewNeeded = 0;
    long long reviewAvail = 0;
    for(int i= 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      totalcomponent += x;
      maxReviewers = max(maxReviewers, y);
      reviewNeeded += (x * (long long)y);
    }
    for(int j= 0; j < m; j++) {
      int x, y;
      cin >> x >> y;
      totalengineer += x;
      int effectiveReviews = min(totalcomponent, y);
      reviewAvail += (x * (long long) effectiveReviews);
    }
    bool valid = true;
    if(totalengineer < maxReviewers) {
      valid = false;
    } else if(reviewAvail < reviewNeeded) {
      valid = false;
    }
    cout << (valid ? 1 : 0) << endl;
  }
  return 0;
}
