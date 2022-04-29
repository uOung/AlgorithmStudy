#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;

int A[55][55];    // A[r][c] = (r, c)에 있는 바구니에 저장되어 있는 물의 양
int d[105];
int s[105];

int checkPreCloud[55][55];

int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};    // ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

queue<pair<int, int> > cloudQ;
queue<pair<int, int> > preCloudQ;

void clearCheckPreCloud() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            checkPreCloud[i][j] = 0;
}

int rangeOfBoard(int number) {
    if(number < 1) return n;
    else if(number > n) return 1;
    else return number;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < m; i++) cin >> d[i] >> s[i];

    cloudQ.push({n, 1}); cloudQ.push({n, 2}); cloudQ.push({n-1, 1}); cloudQ.push({n-1, 2});

    for(int i = 0; i < m; i++) {
        clearCheckPreCloud();

        while(!cloudQ.empty()) {
            // 1. 모든 구름이 di 방향으로 si칸 이동한다.
            pair<int, int> cur = cloudQ.front();

            for(int r = 0; r < s[i]; r++) {
                cur.first += dx[d[i]];
                cur.second += dy[d[i]];

                cur.first = rangeOfBoard(cur.first);
                cur.second = rangeOfBoard(cur.second);
            }
            // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
            A[cur.first][cur.second] += 1;
            // 3. 구름이 모두 사라진다.
            cloudQ.pop(); preCloudQ.push(cur);
            checkPreCloud[cur.first][cur.second] = 1;
        }

        // 4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
        while(!preCloudQ.empty()) {
            pair<int, int> cur = preCloudQ.front(); preCloudQ.pop();
            for(int k = 2; k <= 8; k += 2) {
                int nx = cur.first + dx[k];
                int ny = cur.second + dy[k];

                if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if(A[nx][ny] > 0) A[cur.first][cur.second] += 1;
            }
        }
        // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
        for(int p = 1; p <= n; p++) {
            for(int q = 1; q <= n; q++) {
                if(A[p][q] >= 2) {
                    if(checkPreCloud[p][q] != 1) {
                        cloudQ.push({p, q});
                        A[p][q] -= 2;
                    }
                }
            }
        }
    }

    // M번의 이동이 모두 끝난 후 바구니에 들어있는 물의 양의 합을 구해보자.
    int sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) sum += A[i][j];

    cout << sum;

    return 0;
}
