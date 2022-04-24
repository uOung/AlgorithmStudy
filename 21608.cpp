#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int stuN;

int studentFavorite[410][4];
int students[410];

int sit[30][30];     // (i, j) 좌표 = value(1~n)

int points[] = {0, 1, 10, 100, 1000};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct info {
    int x, y;
    int cntFavorite;
    int cntBlank;
};

info checkMinCol(queue<info> q, int minCol) {

    while(!q.empty()) {
        if(minCol == q.front().y) return q.front();
        q.pop();
    }

    return q.front();
}

info checkMinRow(queue<info> q, int minRow) {
    // maxRow(행번호 중 가장 큰 수)가 여러 자리인 경우 => maxCol
    queue<info> result;
    int minCol = n;

    while(!q.empty()) {
        if(minRow == q.front().x){
            result.push(q.front());
            minCol = min(minCol, q.front().y);
        }
        q.pop();
    }

    if(result.size() > 1) return checkMinCol(result, minCol);
    return result.front();
}

info checkBlankCnt(queue<info> q, int maxBlank) {
    // maxBlank(인접한 칸에 가장 많이 비어있는 칸의 수)가 여러 자리인 경우 => maxRow
    queue<info> result;
    int minRow = n;

    while(!q.empty()) {
        if(maxBlank == q.front().cntBlank) {
            result.push(q.front());
            minRow = min(minRow, q.front().x);
        }
        q.pop();
    }

    if(result.size() > 1) return checkMinRow(result, minRow);
    return result.front();
}

info findSits(queue<info> q, int maxFavorite) {
    // maxFavorite(인접한 칸에 좋아하는 학생들이 가장 많은 수)가 여러 자리인 경우 => maxBlack
    queue<info> result;
    int maxBlank = 0;

    while(!q.empty()) {
        if(maxFavorite == q.front().cntFavorite){
            result.push(q.front());
            maxBlank = max(maxBlank, q.front().cntBlank);
        }

        q.pop();
    }

    if(result.size() > 1) return checkBlankCnt(result, maxBlank);
    return result.front();
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    stuN = n * n;

    // (r1, c1) & (r2, c2) 인접 => (r|r1 - r2| + |c1 - c2| = 1  :: 상하좌우
    // 1. 비어있는 칸 중, 좋아하는 학생이 인접한 칸이 가장 많은 칸
    // 2. (1)의 조건을 만족하는 칸이 여러 개이면, 인접한 칸 중 비어있는 칸이 가장 많은 칸
    // 3. (2)도 만족하는 칸이 여러 개이면, 행(r)의 번호가 가장 작은 칸 => 열(c)의 번호가 가장 작은 칸

    for(int i = 1; i <= stuN; i++) {
        cin >> students[i];
        for(int j = 0; j < 4; j++) cin >> studentFavorite[students[i]][j];
    }

    // 학생마다 자리 정하기
    for(int i = 1; i <= stuN; i++) {
        int maxFavorite = 0, maxBlank = 0;
        queue<info> q;
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                // 비어있는 칸이 아닐경우
                if(sit[j][k] != 0) continue;

                int cntFavorite = 0, cntBlank = 0;
                // (j, k): 비어있는 칸 => 인접한 칸에 students[i]이 좋아하는 학생이 몇명이나 있는지
                // 비어있는 칸의 인접한 칸 살펴보기
                for(int l = 0; l < 4; l++) {
                    int nx = j + dx[l];
                    int ny = k + dy[l];

                    // 자리의 범위를 벗어나는 경우
                    if(nx < 1 || nx > n || ny < 1 || ny > n) continue;

                    // 인접한 칸 중 비어있는 칸일 경우
                    if(sit[nx][ny] == 0){
                        cntBlank++;
                        continue;
                    }

                    for(int p = 0; p < 4; p++) {
                        // (j, k) => 인접한 칸에 students[i]가 좋아하는 학생일 경우
                        if(sit[nx][ny] == studentFavorite[students[i]][p]){
                            cntFavorite++;
                            break;
                        }
                    }
                }
                q.push({j, k, cntFavorite, cntBlank});
                maxFavorite = max(maxFavorite, cntFavorite);
            }
        }
        info result = findSits(q, maxFavorite);
        sit[result.x][result.y] = students[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                 for(int p = 0; p < 4; p++) {
                    if(sit[nx][ny] == studentFavorite[sit[i][j]][p]){
                        cnt++;
                        break;
                    }
                }
            }
            ans += points[cnt];
        }
    }

    cout << ans;

    return 0;
}
