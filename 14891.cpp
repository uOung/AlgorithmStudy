#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 8
#define CNT 4

int k;

// [0] = 12, [1] = 1:30, [2] = 3, [3] = 4:30, [4] = 6, [5] = 7:30, [6] = 9, [7] = 10:30)
int state[CNT][SIZE];

int score[] = { 1, 2, 4, 8 };

void rotate(int num) {
    int last = state[num][SIZE - 1];
    for(int i = SIZE - 1; i > 0; i--)
        state[num][i] = state[num][i - 1];
    state[num][0] = last;
}

void rotateReverse(int num) {
    int last = state[num][0];
    for(int i = 0; i < SIZE - 1; i++)
        state[num][i] = state[num][(i + 1) % SIZE];
    state[num][SIZE - 1] = last;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < CNT; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < SIZE; j++) state[i][j] = s[j] - '0';
    }

    cin >> k;

    for(int i = 0; i < k; i++) {
        int n1, n2; // n1: 회전하는 톱니바퀴의 번호, n2: 회전방향(1: 시계, -1: 반시계)
        cin >> n1 >> n2;
        n1 = n1 - 1;

        // 맞닿을 가능성이 있는 부분: 2, 6
        int dir[CNT] = {0};
        dir[n1] = n2;
        // 왼쪽
        int idx = n1;
        while(idx > 0 && state[idx][6] != state[idx - 1][2]) {
            dir[idx - 1] = -dir[idx];
            idx--;
        }

        // // 오른쪽
        idx = n1;
        while(idx < CNT - 1 && state[idx][2] != state[idx + 1][6]) {
            dir[idx + 1] = -dir[idx];
            idx++;
        }

        // rotate
        for(int i = 0; i < CNT; i++) {
            if(dir[i] == 1) rotate(i);
            else if(dir[i] == -1) rotateReverse(i);
        }
    }

    int ans = 0;

    for(int i = 0; i < CNT; i++) {
        if(state[i][0] == 1) ans += score[i];
    }

    cout << ans;

    return 0;
}
