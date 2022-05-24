#include <iostream>

using namespace std;

int n, s;
int arr[25];
int cnt;

void func(int cur, int sum) {
    if(cur == n) {
        if(sum == s) cnt++;
        return;
    }

    func(cur + 1, sum);    // 다음으로(i + 1) 넘어갈 때, arr[cur]는 부분수열에 포함하지 않는 경우
    func(cur + 1, sum + arr[cur]);    // 다음으로(i + 1) 넘어갈 때, arr[cur]는 부분수열에 포함하는 경우
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    // 원소가 n개인 집합에서 부분집합의 갯수는 2^n
    // 각 원소는 포함되거나 포함되지 않거나 이 2가지의 선택권을 가지고 원소는 총 n개이니 2가 n번 곱해져 2^n
    for(int i = 0; i < n; i++) cin >> arr[i];

    func(0, 0);
    // 크기가 양수인 부분수열: 공집합 제외
    // s == 0: 공집합인 경우가 발생
    if(s == 0) cnt--;
    cout << cnt << "\n";

    return 0;
}
