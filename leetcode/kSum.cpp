#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<vector<int> > > dp;
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int f(int n, int k, int target, vector<int>& A) {
      cout << n << ", " << k << ", " << target << endl;
        if(dp[n][k][target] != -1)
            return dp[n][k][target];
        if(n == 0) {
            return dp[n][k][target] = target == 0 && k == 0 ? 1 : 0;
        }
        if(target >= A[n-1])
            return dp[n][k][target] = f(n-1, k-1, target - A[n-1], A) + f(n-1, k, target, A);
        else
            return dp[n][k][target] = f(n-1, k, target, A);
     }
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n = A.size();
        dp = vector<vector<vector<int> > >(n+1, vector<vector<int> >(k+1, vector<int>(target+1, -1)));
        return f(n, k, target, A);
    }
};

int main() {
  ios::sync_with_stdio(false);
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  Solution sol;
  cout << sol.kSum(v, 2, 5) << endl;
  return 0;
}
