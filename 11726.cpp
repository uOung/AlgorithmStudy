#include <iostream>
#include <algorithm>

using namespace std;

int D[1002]; // D[i] = 2xi의 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수

    // 점화식
    // D[k] = D[k-1] + D[k-2]

    // 초기화
    D[1] = 1; D[2] = 2;

    int num = 10007;
    for(int k = 3; k <= n; k++) D[k] = (D[k-1] + D[k-2])%num;

    cout << D[n];

    return 0;
}
