#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

// N: x(세로), M: y(가로), H:z(높이)
int N, M, H;

// 인접한 범위: 왼, 오, 앞, 뒤, 위, 아래 = 여섯방향
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int box[105][105][105];
int days[105][105][105];

queue<tuple<int, int, int> > Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;

    // 보관 후 하루 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 됨
    // 창고에 보관된 모든 토마토가 익게 되는 최소 일수

    // 0: 익지 않은 토마토, 1: 익은 토마토, -1: 토마토가 들어있지 않은 경우
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) Q.push({i, j, k});
                if(box[i][j][k] == 0) days[i][j][k] = -1;
            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curZ, curX, curY) = cur;

        for(int i = 0; i < 6; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int nz = curZ + dz[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if(days[nz][nx][ny] >= 0) continue;
            days[nz][nx][ny] = days[curZ][curX][curY] + 1;
            Q.push({nz, nx, ny});
        }
    }

    int maxV = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(days[i][j][k] == -1){
                    cout << "-1";
                    return 0;
                }
                maxV = max(maxV, days[i][j][k]);
            }
        }
    }

    cout << maxV;

    return 0;
}
