#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int n, m;

int map[10][10];
int copyMap[10][10];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<pair<int, int> > blankV;
vector<int> idxBlank;

int maxCnt = 0;

void doCopyMap() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            copyMap[i][j] = map[i][j];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          cin >> map[i][j];
          if(map[i][j] == 0) blankV.push_back({i, j});
        }
    }

    idxBlank.resize(blankV.size());
    fill(idxBlank.begin(), idxBlank.end()-3, 0);
    fill(idxBlank.end()-3, idxBlank.end(), 1);


    do {
         doCopyMap();

        for(int i = 0; i < blankV.size(); i++) {
            pair<int, int> cur = blankV[i];
            copyMap[cur.first][cur.second] = idxBlank[i];
        }

        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(copyMap[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = cur.first + dx[k];
                int ny = cur.second + dy[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(copyMap[nx][ny] == 1 || copyMap[nx][ny] == 2) continue;
                copyMap[nx][ny] = 2;
                q.push({nx, ny});
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(copyMap[i][j] == 0) cnt++;

        maxCnt = max(maxCnt, cnt);

    } while(next_permutation(idxBlank.begin(), idxBlank.end()));

    cout << maxCnt;

    return 0;
}
