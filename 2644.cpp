#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 105

int n, m;
int a, b;

vector<int> arr[MAX];
int dist[MAX];
bool visit[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> m;

    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    fill(dist, dist + n + 1, -1);
    queue<int> q;
    q.push(a); visit[a] = true;
    dist[a] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int i = 0; i < arr[cur].size(); i++) {
            int p = arr[cur][i];

            if(visit[p] || dist[p] >= 0) continue;

            visit[p] = true;
            dist[p] = dist[cur] + 1;
            q.push(p);
        }
    }

    cout << dist[b];

    return 0;
}
