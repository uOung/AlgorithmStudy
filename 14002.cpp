#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int a[1005], preIdx[1005];
int d[1005];    // d[i]: i번째 수까지 증가한 길이

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    fill(d, d + 1005, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                if(d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    preIdx[i] = j;
                }
            }
        }
    }

    int maxV = *max_element(d, d + n);

    cout << maxV << "\n";

    int maxIdx = 0;
    for(int i = 0; i < n; i++) {
        if(maxV == d[i]) {
            maxIdx = i;
            break;
        }
    }

    deque<int> ans;
    int cur = maxIdx;

    while(maxV--) {
        ans.push_front(a[cur]);
        cur = preIdx[cur];
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";


    return 0;
}
