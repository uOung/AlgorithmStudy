#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int D[12];

    D[1] = 1;   // 맨 뒤에 3을 붙이는 경우
    D[2] = 2;   // 맨 뒤에 2을 붙이는 경우
    D[3] = 4;   // 맨 뒤에 1을 붙이는 경우

    for(int i = 4; i <= 11; i++) D[i] = D[i-3] + D[i-2] + D[i-1];

    int T;
    cin >> T;

    int n;

    for(int t = 0; t < T; t++) {
        cin >> n;

        cout << D[n] << "\n";
    }



    return 0;
}
