#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int, int> > v;

void copyBoard() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            board2[i][j] = board1[i][j];
}

void upd(int x, int y, int dir) {
    // 방향이 4이상일 경우 다시 재정비
    dir %= 4;

    // 한 방향으로 계속 이동
    while(true) {
        x += dx[dir];
        y += dy[dir];

        // 끝에 도달했을 때, 종료
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        // 벽을 만났을 때, 종료
        if(board2[x][y] == 6) return;

        // cctv를 만나면 건너뛰기
        if(board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int blankCnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if(board1[i][j] > 0 && board1[i][j] < 6)
                v.push_back(make_pair(i, j));

            // cctv가 하나도 없을 수도 있기 때문에 그런 경우를 대비해 blank의 개수 필요
            else if(board1[i][j] == 0) blankCnt++;
        }
    }

    for(int i = 0; i < (1 << (2 * v.size())); i++) {
        copyBoard();

        int tmp = i;
        for(int j = 0; j < v.size(); j++) {
            // 각 cctv의 방향
            int dir = tmp % 4; tmp /= 4;
            int x = v[j].X, y = v[j].Y;

            if(board1[x][y] == 1) {
                upd(x, y, dir);
            }

            else if(board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }

            else if(board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }

            else if(board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }

            else {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }

            int cnt = 0;
            for(int p = 0; p < n; p++)
                for(int q = 0; q < m; q++)
                    if(board2[p][q] == 0) cnt++;

            blankCnt = min(blankCnt, cnt);
        }
    }

    cout << blankCnt;

    return 0;
}
