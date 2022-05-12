#include <iostream>

using namespace std;

int n, k;

int coins[105];
int value[10005];    // value[i] : i값일 때 동전의 최소개수

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> coins[i];

    // value[i] = min(value[j], value[j - coins[i]] + 1);
    fill(value, value + 10005, 10005);
    value[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            value[j] = min(value[j], value[j - coins[i]] + 1);
        }
    }

    if(value[k] == 10005) cout << -1 << "\n";
    else cout << value[k] << "\n";

    return 0;
}
