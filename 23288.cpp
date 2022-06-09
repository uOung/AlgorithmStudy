#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int n, m, k;

int board[30][30];
bool visit[30][30];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int x, y, dir;

int dice[] = {0, 1, 2, 3, 4, 5, 6};
//    2
//  4 1 3
//    5
//    6(아랫면)

int d[4][4] = {
    {6, 3, 1, 4},
    {1, 2, 6, 5},
    {4, 1, 3, 6},
    {2, 1, 5, 6}
};

void clearVisit() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            visit[i][j] = false;
}

void rollDice() {
    int tmp[7];
    for(int i = 0; i < 7; i++) tmp[i] = dice[i];

    for(int i = 0; i < 4; i++) tmp[d[dir][i]] = dice[d[dir][(i + 1) % 4]];

    for(int i = 0; i < 7; i++) dice[i] = tmp[i];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    x = 1, y = 1, dir = 0;
    int A, B, C, ans = 0;
    for(int i = 0; i < k; i++) {
        // 1. 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
        int tmpX = x + dx[dir], tmpY = y + dy[dir];
        if(tmpX <= 0 || tmpX > n || tmpY <= 0 || tmpY > m) dir = (dir + 2) % 4;
        x += dx[dir]; y += dy[dir];
        rollDice();

        // 2. 주사위가 도착한 칸(x, y)에 대한 점수를 획득한다.
        clearVisit();
        A = dice[6]; B = board[x][y]; C = 1;
        queue<pair<int, int> > q;
        q.push(make_pair(x, y)); visit[x][y] = true;
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(int p = 0; p < 4; p++) {
                int nx = cur.X + dx[p];
                int ny = cur.Y + dy[p];

                if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                if(visit[nx][ny] || board[nx][ny] != B) continue;
                C++;
                visit[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
        ans += (B * C);
        // 3. 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸(x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
            // A > B: 시계방향으로 90도
        if(A > B) dir = (dir + 1) % 4;
            // A < B: 반시계방향으로 90도
        if(A < B) dir = (4 + dir - 1) % 4;
            // A = B: 이동방향 변화 X
    }

    cout << ans;


    return 0;
}
