#include <iostream>

using namespace std;

int n, m, x, y, k;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};    // 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4

int map[25][25];
int dice[7];
//     1
//   5 2 6    윗면: 2
//     3
//     4

int d[5][4] = {
    {},
    {2, 6, 4, 5},    // 동: 2->6, 6->4, 4->5, 5->2
    {2, 5, 4, 6},    // 서: 2->5, 5->4, 4->6, 6->2
    {2, 1, 4, 3},    // 북: 2->1, 1->4, 4->3, 3->2
    {2, 3, 4, 1}     // 남: 2->3, 3->4, 4->1, 1->2
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int command;
    for(int i = 0; i < k; i++) {
        cin >> command;
        int nx = x + dx[command];
        int ny = y + dy[command];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        int temp[7];
        for(int t = 1; t <= 6; t++) temp[t] = dice[t];

        for(int p = 0; p < 4; p++) temp[d[command][p]] = dice[d[command][(p+1) % 4]];
        for(int t = 1; t <= 6; t++) dice[t] = temp[t];

        // 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
        if(map[nx][ny] == 0) map[nx][ny] = dice[4];

        // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
        else {
            dice[4] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout << dice[2] << "\n";    // 주사위 윗면 출력

        x = nx; y = ny;
    }

    return 0;
}
