#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m, k, x, y, direction;

int map[25][25];
int visit[25][25];

// 0: 동 1: 남, 2: 서, 3: 북
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int otherD[] = {2, 3, 0, 1};

int dice[7] = {0, 1, 2, 3, 4, 5, 6};
//   2
// 4 1 3    위: 1
//   5
//   6

int d[4][4] = {
    {6, 3, 1, 4},
    {6, 5, 1, 2},
    {6, 4, 1, 3},
    {6, 2, 1, 5}
};

void clearVisit() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            visit[i][j] = 0;
}

void roll() {
    int temp[7];
    for(int i = 1; i <= 6; i++) temp[i] = dice[i];

    for(int i = 0; i < 4; i++) temp[d[direction][i]] = dice[d[direction][(i+1) % 4]];

    for(int i = 1; i <= 6; i++) dice[i] = temp[i];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> map[i][j];

    x = 1; y = 1;
    direction = 0;

    int sum = 0;
    for(int i = 0; i < k; i++) {
        // 1. 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(nx < 1 || nx > n || ny < 1 || ny > m) {
            direction = otherD[direction];
            nx = x + dx[direction];
            ny = y + dy[direction];
        }

        x = nx; y = ny;
        // 2. 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
        // 칸 (x, y)에 대한 점수는 다음과 같이 구할 수 있다.
        // (x, y)에 있는 정수를 B라고 했을때, (x, y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수 C를 모두 구한다.
        // 이때 이동할 수 있는 칸에는 모두 정수 B가 있어야 한다. 여기서 점수는 B와 C를 곱한 값이다.
        clearVisit();
        queue<pair<int, int> > q;
        q.push({x, y});
        visit[x][y] = 1;
        int C = 1;

        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(int p = 0; p < 4; p++) {
                int px = cur.first + dx[p];
                int py = cur.second + dy[p];

                if(px < 1 || px > n || py < 1 || py > m) continue;
                if(visit[px][py] == 1 || map[px][py] != map[x][y]) continue;
                C++;
                visit[px][py] = 1;
                q.push({px, py});
            }
        }

        sum += (map[x][y] * C);

        // 3. 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
        roll();
        // A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
        if(dice[6] > map[x][y]) direction = (direction+1) % 4;
        // A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
        else if(dice[6] < map[x][y]) {
            if(direction == 0) direction = 3;
            else direction -= 1;
        }
        // A = B인 경우 이동 방향에 변화는 없다.
    }

    cout << sum;


    return 0;
}
