#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char arr[20];
int idx[20];
bool isused[20];

void func(int k) {
    if(k == l) {
        for(int i = 0; i < l; i++) cout << arr[idx[i]];
        cout << "\n";
        return;
    }

    int st = 0;
    if(k != 0) st = idx[k - 1] + 1;
    for(int i = st; i < c; i++) {
        if(isused[i]) continue;

        isused[i] = true;
        idx[k] = i;
        func(k + 1);
        isused[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for(int i = 0; i < c; i++) cin >> arr[i];
    sort(arr, arr + c);

    func(0);

    return 0;
}
