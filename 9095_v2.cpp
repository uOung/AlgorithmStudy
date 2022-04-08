#include <iostream>
#include <algorithm>

using namespace std;

int D[302];    // D[i]: i번째까지 밟지 않을 계단의 최솟값, i번째 계단은 절대 밟지 않음
int S[302];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int sum = 0;

    for(int i = 1; i <= N; i++) {
        cin >> S[i];
        sum += S[i];
    }

    D[1] = S[1];
    D[2] = S[2];
    D[3] = S[3];

    // i-2 or i-1 중 하나는 무조건 밟지 않아야하므로, 둘 중 최소의 합인 경우로 선택
    for(int i = 4; i < N; i++)
        D[i] = min(D[i-2], D[i-3]) + S[i];

    // 계단의 총 합 - 계단을 밟지 않은 계단의 최소의 총 합
    cout << sum-min(D[N-1], D[N-2]);


    return 0;
}
