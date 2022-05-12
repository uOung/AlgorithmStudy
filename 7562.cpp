#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int T, l;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int board[305][305];
int dist[305][305];

pair<int, int> nStart, nEnd;

queue<pair<int, int> > q;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> l;
        for(int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);

        cin >> nStart.X >> nStart.Y >> nEnd.X >> nEnd.Y;
        dist[nStart.X][nStart.Y] = 0;
        q.push({nStart.X, nStart.Y});

        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(int p = 0; p < 8; p++) {
                int nx = cur.X + dx[p];
                int ny = cur.Y + dy[p];

                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }

        cout << dist[nEnd.X][nEnd.Y] << "\n";

    }

    return 0;
}
