#include <iostream>
#include <cstring>

using namespace std;

int v[101];
long long dp[101][101][2];


long long f(int start, int end, int dir) {
  dir = dir > 0 ? dir : 0;
  if(dp[start][end][dir] > -2000000) {
    return dp[start][end][dir];
  }
  long long result = -2000000;
  if(start > end) {
    return 0;
  }
  if(start == end) {
     result = v[start];
     dp[start][end][dir] = result;
     return result;
   }
   for(int i = 1; i <= end - start+1; i++) {
     long long asum = 0;
     if(dir == 1) {
       // left to right
       for(int j = start; j <= start + i - 1; j++) {
	 asum += v[j];
       }
       // cout << "left to right: asum is " << asum << endl;
       // cout << "result start is " << result << endl;
       // cout << "compare 1: " << start+i << ", " << end << ": " << f(start+i, end, 1) << endl;
       // cout << "compare 2: " << start + i << ", " <<  end << ": " << f(start+i, end, -1) << endl;
       result = max(result, asum - max(f(start + i, end, 1), f(start + i , end, -1)));
     }
     else {
       // right to left
       for(int j= end; j >= end - i + 1; j--) {
	 asum += v[j];
       }
       // cout << "right to left: asum is " << asum << endl;
       // cout << "result start is " << result << endl;
       // cout << "compare 1: " << start << ", " << end-i << ": " << f(start, end-i, 1) << endl;
       // cout << "compare 2: " << start << ", " << end - i << ": " << f(start, end-i, -1) << endl;
       result = max(result, asum - max(f(start, end - i, 1), f(start, end - i , -1)));
     }
   }
   dp[start][end][dir] = result;
   return result;
 }

 int main() {
   int n;
   while(cin >> n && n) {
     memset(dp, -2000000, sizeof dp);
     for(int i = 0; i < n; i++) {
       int x;
       cin >> x;
       v[i] = x;
     }
     // cout << "f(0, 1, 1) , f(0, 1, -1)" << endl;
     // cout << f(0, 2, 1) << ", " << f(0, 2, -1) << endl;
     long long result = max(f(0, n-1, 1), f(0, n-1, -1));
     cout << result << endl;
  }
  return 0;
}
