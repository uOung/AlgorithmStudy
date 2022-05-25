#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int l, c;
string board[5];
bool check[25];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) cin >> board[i];

    fill(check + 7, check + 25, true);

    int ans = 0;
    do {
        queue<pair<int, int> > q;

        int sCnt = 0, adj = 0;
        bool sevenP[5][5] = {}, visit[5][5] = {};

        for(int i = 0; i < 25; i++) {
            if(check[i]) continue;

            int x = i / 5; int y = i % 5;
            sevenP[x][y] = true;
            if(q.empty()) {
                q.push(make_pair(x, y));
                visit[x][y] = true;
            }
        }

        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            adj++;    // 가로세로로 인접한 사람의 수
            if(board[cur.X][cur.Y] == 'S') sCnt++;
            for(int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(visit[nx][ny] || !sevenP[nx][ny]) continue;
                // sevenP == true인 사람들이 인접
                q.push(make_pair(nx, ny));
                visit[nx][ny] = true;
            }
        }

        if(adj >= 7 && sCnt >= 4) ans++;

    } while(next_permutation(check, check + 25));

    cout << ans;

    return 0;
}
