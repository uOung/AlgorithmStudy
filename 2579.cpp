#include <iostream>
#include <algorithm>

using namespace std;

int D[302][3];    // D[i][j]: j번 연속으로 계단을 밟은 후, i번째 계단을 밟고서의 최대 점수
int S[302];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> S[i];

    D[1][1] = S[1]; D[1][2] = 0;
    D[2][1] = S[2]; D[2][2] = S[1] + S[2];

    // 1. 한 번에 1칸 or 2칸
    // 2. 3칸 연속 X
    // 3. 마지막 계단은 무조건 밟음

    for(int i = 3; i <= N; i++){
        // i 첫번째 계단으로(연속X) 밟으려면, 이전(i-1)은 무조건 밟지 않아야 j==1이 될 수 있음
        // i-2번째의 최대 값을 가져와 현재 계단의 점수를 +
        D[i][1] = max(D[i-2][1], D[i-2][2]) + S[i];
        // i 두번째 계단으로(연속O) 밟으려면, 이전(i-1)은 무조건 밟아야 하며 i-1은 무조건 j==1
        D[i][2] = D[i-1][1] + S[i];
    }

    cout << max(D[N][1], D[N][2]);

    return 0;
}
