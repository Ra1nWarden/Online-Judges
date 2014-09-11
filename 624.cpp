#include <iostream>
#include <vector>

using namespace std;

vector<int> findMax(const vector<int>& tracks, int a, int remain, vector<int> picked) {
    if (a == tracks.size()) {
        return picked;    
    }  else {
        int nextSong = tracks[a];
        if (nextSong > remain) {
            // cannot record it
            return findMax(tracks, a+1, remain, picked);
        } else {
            vector<int> notRecord = findMax(tracks, a+1, remain, picked);
            remain -= nextSong;
            picked.push_back(nextSong);
            vector<int> record = findMax(tracks, a+1, remain, picked);
            int sumNot = 0;
            int sumYes = 0;
            for (int i = 0; i < notRecord.size(); i++)
                sumNot += notRecord[i];
            for (int i = 0; i < record.size(); i++)
                sumYes += record[i];
            return sumNot > sumYes ? notRecord : record;
        }
    } 
}

int main() {
    int n, d;
    while(cin >> n >> d) {
        vector<int> tracks;
        for (int i = 0; i < d; i++) {
            int length;
            cin >> length;
            tracks.push_back(length);
        }    
        vector<int> picked;
        vector<int> result = findMax(tracks, 0, n, picked);
        int maxLength = 0;
        for (int i = 0; i < result.size(); i++) {
            maxLength += result[i];
            cout << result[i] << " ";    
        }
        cout << "sum:" << maxLength << endl;
    }
    return 0;    
}
