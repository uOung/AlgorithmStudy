#include <iostream>
#include <algorithm>

using namespace std;

int s[100005];

int D[100005];    // D[i] = i에서 연속된 수의 최대의 합

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        D[i] = s[i];
    }

    for(int i = 2; i <= n; i++)
        D[i] = max(D[i], D[i-1] + s[i]);

    cout << *max_element(D + 1, D+n+1);

    return 0;
}
