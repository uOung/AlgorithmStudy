#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10], num[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout << num[arr[i]] << " ";
        cout << "\n";
        return;
    }

    int tmp = -1;
    for(int i = 0; i < n; i++) {
        if(isused[i] || tmp == num[i]) continue;

        isused[i] = true;
        arr[k] = i;
        func(k + 1);
        isused[i] = false;
        tmp = num[arr[k]];
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];

    sort(num, num + n);

    func(0);

    return 0;
}
