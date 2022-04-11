#include <iostream>
#include <algorithm>

using namespace std;

int num[100002];
int D[100002]; // D[i] = 1부터 i번째까지의 합

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    // 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합
    // N: 수의 개수, M: 합을 구해야 하는 횟수
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> num[i];

    // 점화식
    // D[k] = D[k-1] + num[k];
    // result = D[j] - D[i-1];

    // 초기값 설정
    D[1] = num[1];
    for(int k = 2; k <= N; k++) D[k] = D[k-1] + num[k];

    int i, j;
    for(int k = 1; k <= M; k++) {
        cin >> i >> j;
        cout << D[j] - D[i-1] << "\n";
    }

    return 0;
}
