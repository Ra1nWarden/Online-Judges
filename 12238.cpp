#include <iostream>
#include <vector>

using namespace std;

long long parents[100001];
long long length[100001];
long long distances[100001];
bool visited[100001];

void init() {
    for (long long i = 0; i <= 100000; i++) {
        parents[i] = i;
        length[i] = 0;
        distances[i] = 0;
    }
}

void reset(long long n) {
    for (long long i = 0; i < n; i++) {
        visited[i] = false;
        distances[i] = 0;
    }
}

long long query(int start, int end) {
   visited[start] = true;
   long long next = parents[start];
   visited[next] = true;
   distances[next] = length[start];
   while(next != 0) {
        long long addLength = length[next] + distances[next];
        next = parents[next];
        visited[next] =true;
        distances[next] = addLength;
   }

   long long nextEnd = end;
   while(!visited[nextEnd]) {
        visited[nextEnd] = true;
        long long addLength = length[nextEnd] + distances[nextEnd];
        nextEnd = parents[nextEnd];
        distances[nextEnd] += addLength;
   }

   return distances[nextEnd];
}

int main() {
    init();
    long long edges;
    while(cin >> edges && edges) {
        for (long long i = 1; i < edges; i++) {
                long long parent, l;
                cin >> parent >> l;
                parents[i] = parent;
                length[i] = l;
        }
        long long queries;
        cin >> queries;
        for (long long j = 0; j < queries; j++) {
            long long start, end;
            cin >> start >> end;
            reset(edges);
            long long nextResult = query(start, end);
            if (j != queries - 1)
                cout << nextResult << " ";
            else
                    cout << nextResult << endl;
        }
    }        
    return 0;
}
