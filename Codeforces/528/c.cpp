#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;

int main() {
    vector<II> coord;
    for(int i = 0; i < 3; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        coord.push_back(make_pair(x, y));
    }
    sort(coord.begin(), coord.end());
    vector<II> ans;
    int ymin = min(coord[0].second, coord[1].second);
    ymin = min(ymin, coord[2].second);
    int ymax = max(coord[0].second, coord[1].second);
    ymax = max(ymax, coord[2].second);
    if(coord[0].first == coord[2].first) {
        for(int i = coord[0].second; i <= coord[2].second; i++)
            ans.push_back(make_pair(coord[0].first, i));
    } else if (coord[0].first == coord[1].first) {
        for(int y = ymin; y <= ymax; y++)
            ans.push_back(make_pair(coord[0].first, y));
        for(int x = coord[0].first + 1; x <= coord[2].first; x++)
            ans.push_back(make_pair(x, coord[2].second));
    } else if (coord[1].first == coord[2].first) {
        for(int y = ymin; y <= ymax; y++)
            ans.push_back(make_pair(coord[1].first, y));
        for(int x = coord[0].first; x < coord[2].first; x++)
            ans.push_back(make_pair(x, coord[0].second));   
    } else {
        for(int y = ymin; y <= ymax; y++)
            ans.push_back(make_pair(coord[1].first, y));

        for(int x = coord[0].first; x < coord[1].first; x++)
            ans.push_back(make_pair(x, coord[0].second));

        for(int x = coord[1].first + 1; x <= coord[2].first; x++)
            ans.push_back(make_pair(x, coord[2].second));
    }

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}