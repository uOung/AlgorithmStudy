#include <iostream>

using namespace std;
using ll = long long;

ll a, b, c;

ll func(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    // a^b * a^b = a^2b
    ll val = func(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;

    // 홀수: a^2b * a
    return val * a % c;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << func(a, b, c);

    return 0;
}
