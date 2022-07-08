#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1005][1005];
bool visit[1005];

int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int n1, n2;
    for(int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        arr[n1][n2] = 1;
        arr[n2][n1] = 1;
    }

    queue<int> q;
    for(int t = 1; t <= n; t++) {
        if(visit[t]) continue;
        q.push(t); visit[t] = true;
        ans++;

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(int i = 1; i <= n; i++) {
                if(visit[i]) continue;
                if(!arr[cur][i]) continue;

                visit[i] = true;
                q.push(i);
            }
        }
    }

    cout << ans;

    return 0;
}
