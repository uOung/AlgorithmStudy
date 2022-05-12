#include <iostream>

using namespace std;

int n, k;
int coins[105];
int d[100005];    // d[i]: i값일 때 가질 수 있는 경우의 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> coins[i];


    d[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = coins[i]; j <= k; j++)
            d[j] += d[j - coins[i]];

    cout << d[k] << "\n";

    return 0;
}
