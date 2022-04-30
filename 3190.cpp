#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

// 0: 동, 1: 남, 2:서, 3: 북

int n, K, L;
int d;
pair<int, int> head, tail;

int apple[105][105];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 1: L(반시계방향) 2: R(시계방향)
queue<pair<int, int> > changeQ;
queue<pair<int, int> > snakeQ;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;

    for(int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        apple[r][c] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++) {
        int x; char c;
        cin >> x >> c;
        if(c == 'L') changeQ.push({x, 1});
        else changeQ.push({x, 2});
    }

    int t = 0;
    int rotateT = changeQ.front().X;
    int rotateD = changeQ.front().Y;
    changeQ.pop();

    head = make_pair(1, 1); tail = make_pair(1, 1);
    snakeQ.push(head);
    while(true) {

        if(rotateT == t) {
            if(rotateD == 2) d = (d + 1) % 4;
            else {
                if(d == 0) d = 3;
                else d = d - 1;
            }

            if(!changeQ.empty()) {
                rotateT = changeQ.front().X;
                rotateD = changeQ.front().Y;
                changeQ.pop();
            }
        }

        int nx = head.X + dx[d];
        int ny = head.Y + dy[d];

        t++;
        if(nx < 1 || nx > n || ny < 1 || ny > n) break;

        queue<pair<int, int> > temp;
        temp = snakeQ;

        bool check = false;
        while(!temp.empty()) {
            pair<int, int> cur = temp.front(); temp.pop();
            if(nx == cur.X && ny == cur.Y) check = true;
        }

        if(check) break;

        // 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        head.X = nx; head.Y = ny;
        snakeQ.push(head);
        // 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        if(apple[head.X][head.Y] == 1)
            apple[head.X][head.Y] = 0;

        // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        else {
            snakeQ.pop();
            tail.X = snakeQ.front().X;
            tail.Y = snakeQ.front().Y;
        }

    }

    cout << t;

    return 0;
}
