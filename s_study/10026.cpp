#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int n;

int normal[105][105];    // 1: G, 2: B, 3: R
int non_normal[105][105];

int visit[105][105];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int result1, result2;

void clearVisit() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            visit[i][j] = 0;
}

int bfs(int picture[][105]) {
    clearVisit();
    int result = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visit[i][j] == 1) continue;

            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            visit[i][j] = 1;
            int color = picture[i][j];

            result++;

            while(!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();

                for(int p = 0; p < 4; p++) {
                    int nx = cur.X + dx[p];
                    int ny = cur.Y + dy[p];

                    if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                    if(visit[nx][ny] == 1 || picture[nx][ny] != color) continue;

                    visit[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return result;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if(c == 'R') {
                normal[i][j] = 3;
                non_normal[i][j] = 2;
            }
            else if(c == 'G') {
                normal[i][j] = 2;
                non_normal[i][j] = 2;
            }
            else {
                normal[i][j] = 1;
                non_normal[i][j] = 1;
            }
        }
    }

    cout << bfs(normal) << " " << bfs(non_normal) << "\n";

    return 0;
}
