#include <iostream>

using namespace std;

int n;
int cnt;

bool isusedCol[15];
// 1: 우측상단 좌측하단(x + y 가 모두 동일)
// 2: 좌측상단 우측하단(x - y 가 모두 동일)
bool isusedD1[35], isusedD2[35];

// n-queen: 행 당 하나의 queen이 있을 수 있음
// cur = 현재 행의 번호
void func(int cur) {
    if(cur == n) {
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(isusedCol[i] || isusedD1[i + cur] || isusedD2[i - cur + n - 1]) continue;

        isusedCol[i] = true;
        // i - cur + n - 1: 왜 이렇게 하는지 모르겠으면 직접 해보기
        isusedD1[i + cur] = true; isusedD2[i - cur + n - 1] = true;
        func(cur + 1);
        isusedCol[i] = false;
        isusedD1[i + cur] = false; isusedD2[i - cur + n - 1] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    func(0);

    cout << cnt << "\n";

    return 0;
}
