#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int w, h;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int map[55][55];
bool check[55][55];

void clearVisit() {
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            check[i][j] = false;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> map[i][j];


        clearVisit();

        int ans = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(map[i][j] == 0 || check[i][j]) continue;
                ans++;
                queue<pair<int, int> > q;
                q.push(make_pair(i, j)); check[i][j] = true;

                while(!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for(int p = 0; p < 8; p++) {
                        int nx = cur.X + dx[p];
                        int ny = cur.Y + dy[p];

                        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if(map[nx][ny] == 0 || check[nx][ny]) continue;
                        check[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
