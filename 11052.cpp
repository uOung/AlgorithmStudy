#include <iostream>

using namespace std;

int n;
int p[1005];
int d[1005];   // d[i]: i개의 카드를 갖기 위해 지불해야 하는 금액의 최댓값

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> p[i];

    // n개의 카드를 갖기 위해 지불해야 하는 금액의 최댓값
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            d[j] = max(d[j], d[j - i] + p[i]);
        }
    }

    cout << d[n];

    return 0;
}
