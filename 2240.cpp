#include <iostream>
#include <algorithm>

using namespace std;

int t, w;
int fruit[1005];
int d[1005][35][3];    // d[i][j][k]: i초 때, j번 움직여, k번째 나무 밑에 있을 때 자두가 받을 수 있는 자두의 최대 개수

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;

    for(int i = 1; i <= t; i++)
        cin >> fruit[i];

    for(int i = 1; i <= t; i++) {
        // i초에 한번도 움직이지 않은 경우(1번 나무에 쭈욱-): 이전 초에 한번도 움직이지 않고 1번나무에 있을 때
        d[i][0][1] = d[i - 1][0][1] + (fruit[i] == 1 ? 1 : 0);
        for(int j = 1; j <= w; j++) {
            if(i < j) break;

            // i초에 자두가 떨어지는 나무가 1번 나무일 경우
            if(fruit[i] == 1) {
                // 1번 나무에서 떨어지는 자두를 받는 경우: max(이전 초에서 2번 나무에 있을 때, 이전 초에서 1번 나무에 있었는데 그대로) + 1(현재 1번 나무에서 떨어지는 자두를 받음)
                d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
                // 2번 나무에서 떨어지는 자두를 못받는 경우: max(이전 초에서 1번 나무에 있을 때, 이전 초에서 2번 나무에 있었는데 지금도 그대로)
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
            }

                // i초에 자두가 떨어지는 나무가 2번 나무일 경우
            else {
                // 1번 나무에서 떨어지는 자두를 못받는 경우: max(이전 초에서 2번 나무에 있을 때, 이전 초에서 1번 나무에 있었는데 그대로)
                d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
                // 2번 나무에서 떨어지는 자두를 받는 경우: max(이전 초에서 1번 나무에 있을 때, 이전 초에서 2번 나무에 있었는데 그대로) + 1(현재 2번 나무에서 떨어지는 자두를 받음)
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= w; i++) ans = max(d[t][i][1], d[t][i][2]);

    cout << ans;

    return 0;
}
