#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int T, m, n, k;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int ground[55][55];
int visit[55][55];

void clearVariable() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ground[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t = 0; t < T; t++) {

        cin >> m >> n >> k;

        int result = 0;
        clearVariable();

        for(int i = 0; i < k; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            ground[n1][n2] = 1;
        }

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //       cout << i << " " << j << " " << ground[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(ground[i][j] == 0) continue;
                if(visit[i][j] == 1) continue;

                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visit[i][j] = 1;
                result++;

                while(!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for(int p = 0; p < 4; p++) {
                        int nx = cur.X + dx[p];
                        int ny = cur.Y + dy[p];

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visit[nx][ny] == 1 || ground[nx][ny] == 0) continue;
                        visit[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }

            }
        }

        cout << result << "\n";
    }

    return 0;
}
