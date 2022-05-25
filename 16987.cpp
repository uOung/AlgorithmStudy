#include <iostream>
#include <algorithm>

using namespace std;

int n;
int s[10], w[10];
int maxV, cnt;    // maxV: 가장 많이 깨진 계란의 수, cnt: 현재까지 깨진 계란의 수

void func(int k) {
    if(k == n) {
        maxV = max(maxV, cnt);
        return;
    }

    // 현재 손에 든 계란이 깨졌거나, 현재까지 손에 든 계란 이외에 모든 계란이 깨졌을 경우
    if(s[k] <= 0 || cnt == n - 1) {
        // 그 다음 오른쪽으로 한 칸 이동
        func(k + 1);
        return;
    }

    for(int i = 0; i < n; i++) {
        // 자기자신 or 이미 깨진 계란
        if(i == k || s[i] <= 0) continue;

        // k: 현재 들고 있는 계란, i: 깨려는 계란
        s[k] -= w[i];
        s[i] -= w[k];
        if(s[k] <= 0) cnt++;
        if(s[i] <= 0) cnt++;

        // 계란을 깬 후에 오른쪽 계란으로 이동
        func(k + 1);

        // 다시 원래되로 되돌리기
        if(s[k] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[k] += w[i];
        s[i] += w[k];

    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> w[i];

    func(0);

    cout << maxV;

    return 0;
}
