#include <iostream>

using namespace std;

#define MOD 1000000009

int T, n;
int d[1000005]; // d[i]: i(수)일 때 1, 2, 3의 합으로 나타내는 방법의 수

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i <= 1000000; i++)
        for(int j = 1; j <= 3; j++)
            d[i] = (d[i] + d[i - j]) % MOD;



    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> n;

        cout << d[n] << "\n";
    }

    return 0;
}
