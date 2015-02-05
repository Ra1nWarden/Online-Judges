#include <iostream>
#include <cstring>
#include <cstdlib>
#define INF 2e8

using namespace std;

int n;
int dist[101][101];

int main() {
    while(cin >> n && n) {
        string line;
        getline(cin, line);
        dist[0][0] = 0;
        for(int i = 1; i <= n-1; i++) {
            dist[i][i] = 0;
            for(int j = 0; j < i; j++) {
	      if(j == i -1)
		getline(cin, line);
	      else
                getline(cin, line, ' ');
	      //cout << "i is " << i << " line is " << line << endl;
	      if(line == "x") {
		dist[i][j] = INF;
		dist[j][i] = INF;
	      }
                else {
                    int weight = atoi(line.c_str());
                    dist[i][j] = weight;
                    dist[j][i] = weight;
                }
            }
        }

	// for(int i= 0; i < n; i++) {
	//   for(int j= 0; j < n; j++)
	//     cout << dist[i][j] << " ";
	//   cout << endl;
	// }

        for(int i=  0; i <= n-1; i++) {
            for(int j = 0; j <= n-1; j++) {
                for(int k = 0; k <= n-1; k++) {
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }

	// cout << endl;
	// for(int i= 0; i < n; i++) {
	//   for(int j= 0; j < n; j++)
	//     cout << dist[i][j] << " ";
	//   cout << endl;
	// }

        int result = 0;
        for(int i= 0; i <=n-1; i++)
	  result = max(result, dist[0][i]);
        cout << result << endl;
    }
    return 0;
}

