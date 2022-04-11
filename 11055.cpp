#include <iostream>
#include <algorithm>

using namespace std;

int s[1005];
int d[1005];    // D[i] = i에서 연속된 수의 최대의 합

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s[i];
        d[i] = s[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(s[i] > s[j]) d[i] = max(d[i], d[j] + s[i]);
        }
    }

    cout << *max_element(d, d+N);

    return 0;
}
