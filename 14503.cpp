#include <iostream>
#include <utility>

using namespace std;

int n, m, curX, curY, curD, cnt;

int board[55][55];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int rotateLeft[] = {3, 0, 1, 2};    // 북, 동, 남, 서

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> curX >> curY >> curD;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 각 칸: 빈 칸 or 벽
    // 1. 현재 위치를 청소한다.
    // 2. 현재 위치에서 다음을 반복하면서 인접한 칸을 탐색한다.
    //     a. 현재 위치의 바로 왼쪽에 아직 청소하지 않은 빈 공간이 존재한다면, 왼쪽 방향으로 회전한 다음 한 칸을 전진하고 1번으로 돌아간다. 그렇지 않을 경우, 왼쪽 방향으로 회전한다. 이때, 왼쪽은 현재 바라보는 방향을 기준으로 한다.
    //     b. 1번으로 돌아가거나 후진하지 않고 2a번 단계가 연속으로 네 번 실행되었을 경우, 바로 뒤쪽이 벽이라면 작동을 멈춘다. 그렇지 않다면 한 칸 후진한다.

    while(true) {
        if(board[curX][curY] == 0) cnt++;
        board[curX][curY] = -1;

        bool clean = false;
        for(int i = 0; i < 4; i++) {
            curD = rotateLeft[curD];

            if(board[curX + dx[curD]][curY + dy[curD]] == 0) {
                curX += dx[curD]; curY += dy[curD];
                clean = true;
                break;
            }
        }

        if(clean) continue;
        // 북(0) <=> 남(2) || 동(1) <=> 서(3)
        curX -= dx[curD];
        curY -= dy[curD];
        if(board[curX][curY] == 1) break;

    }

    cout << cnt;

    return 0;
}
