#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> v;
int d[45];    // d[i]: 좌석의 개수가 i개일 때, 사람들이 좌석에 앉을 수 있는 경우의 수

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    v.push_back(0);
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(n + 1);

    // 피보나치 수열의 특성을 가짐.
    d[0] = 1; d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++) d[i] = d[i - 1] + d[i - 2];

    // ex) _ _ _ vip1 _ _ vip2 _ _
    // ~ vip1: 3개의 좌석의 경우의 수 = A
    // vip1 ~ vip2: 2개의 좌석의 경우의 수 = B
    // ~ n(index): 2개의 좌석의 경우의 수 = C
    // => 총 경우의 수: A * B * C = 모든 경우의 수의 곱
    int result = 1;
    for(int i = 1; i < v.size(); i++) result *= d[v[i] - v[i - 1] - 1];

    cout << result;

    return 0;
}
