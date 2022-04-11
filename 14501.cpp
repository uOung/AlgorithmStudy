#include <iostream>
#include <algorithm>

using namespace std;

int D[18]; // D[i] = i번째 날에 상담을 시작했을 때 얻을 수 있는 최대 수익

int T[18];
int P[18];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> T[i] >> P[i];

    for(int i = N; i > 0; i--) {
        // i번째 날에 일을 했을 경우
        if(i+T[i] <= N+1) {
            D[i] = max(P[i]+D[i+T[i]], D[i+1]);
        }
        // i번째 날에 일을 하지 않았을 경우
        else D[i] = D[i+1];
    }

    cout << D[1];

    return 0;
}
