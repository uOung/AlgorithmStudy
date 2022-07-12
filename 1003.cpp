#include <iostream>

using namespace std;

int T, n;
int zero[45], one[45];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    zero[0] = 1; one[1] = 1;

    for(int i = 2; i < 41; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }


    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> n;
        cout << zero[n] << " " << one[n] << "\n";
    }

    return 0;
}
