#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int n, m, minD = 0x7f7f7f7f;

vector<pair<int, int> > houseV;
vector<pair<int, int> > chickenV;
vector<int> idxChicken;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            if(num == 1) houseV.push_back({i, j});
            else if(num == 2) chickenV.push_back({i, j});
        }
    }

    for(int i = 0; i < chickenV.size() - m; i++) idxChicken.push_back(0);
    for(int i = chickenV.size() - m; i < chickenV.size(); i++) idxChicken.push_back(2);

    do {

        vector<pair<int, int> > curChicken;
        for(int i = 0; i < chickenV.size(); i++) {
            pair<int, int> cur = chickenV[i];
            if(idxChicken[i] == 2) curChicken.push_back(cur);
        }

        int sumD = 0; // ?
        for(int i = 0; i < houseV.size(); i++) {
            // 집(houseCur.first, houseCur.second) 에서 가장 가까운 거리에 있는 치킨집과의 거리
            int minimum = 0x7f7f7f7f; // ?
            for(int k = 0; k < curChicken.size(); k++) {
                pair<int, int> cur = curChicken[k];
                int d = abs(cur.first - houseV[i].first) + abs(cur.second - houseV[i].second);
                minimum = min(minimum, d);
            }

            sumD += minimum;

        }

        minD = min(minD, sumD);

    } while(next_permutation(idxChicken.begin(), idxChicken.end()));

    cout << minD;

    return 0;
}
