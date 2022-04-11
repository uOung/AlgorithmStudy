#include <iostream>
#include <algorithm>

using namespace std;

int R[1002];
int G[1002];
int B[1002];

// D[i][0] = i번째 집까지 칠하는 비용의 최소값, 단 i번째 집은 R
// D[i][1] = i번째 집까지 칠하는 비용의 최소값, 단 i번째 집은 G
// D[i][2] = i번째 집까지 칠하는 비용의 최소값, 단 i번째 집은 B
int D[1002][3];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> R[i] >> G[i] >> B[i];

    // 1번 집과 2번 집의 색은 달라야 한다.
    // N번 집과 N-1번 집의 색은 달라야 한다.
    // i번 집은 i-1, i+1번 집의 색깔과 달라야 한다.

    // 점화식
    // D[k][0] = min(D[k-1][1], D[k-1][2]) + R[k]
    // D[k][1] = min(D[k-1][0], D[k-1][2]) + G[k]
    // D[k][2] = min(D[k-1][0], D[k-1][1]) + B[k]

    // 초기화
    D[1][0] = R[1]; D[1][1] = G[1]; D[1][2] = B[1];

    for(int k = 2; k <= N; k++) {
        D[k][0] = min(D[k-1][1], D[k-1][2]) + R[k];
        D[k][1] = min(D[k-1][0], D[k-1][2]) + G[k];
        D[k][2] = min(D[k-1][0], D[k-1][1]) + B[k];
    }

    cout << min(D[N][0], min(D[N][1], D[N][2]));

    return 0;
}
