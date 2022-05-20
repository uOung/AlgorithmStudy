#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 35

int l, r, c;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;

        char board[MAX][MAX][MAX];
        int dist[MAX][MAX][MAX];

        for(int i = 0; i < l; i++)
            for(int j = 0; j < r; j++)
                fill(dist[i][j], dist[i][j] + c, 0);

        queue<tuple<int, int, int> > q;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S')
                        q.push({i, j, k});

                    else if(board[i][j][k] == '.') dist[i][j][k] = -1;
                }
            }
        }

        bool check = false;
        while(!q.empty()) {
            tuple<int, int, int> cur = q.front(); q.pop();
            int curX, curY, curZ;
            tie(curX, curY, curZ) = cur;

            for(int i = 0; i < 6; i++) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                int nz = curZ + dz[i];

                if(nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
                if(board[nx][ny][nz] == '#' || dist[nx][ny][nz] > 0) continue;
                dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                if(board[nx][ny][nz] == 'E') {
                    cout << "Escaped in " << dist[nx][ny][nz] << " minute(s).\n";
                    check = true;
                    break;
                }
                q.push({nx, ny, nz});
            }
        }

        if(!check) cout << "Trapped!" << "\n";

    }

    return 0;
}
