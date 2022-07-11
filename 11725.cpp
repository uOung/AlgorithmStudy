#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100005

int n, m;
vector<int> v[MAX];
bool visit[MAX];
int ans[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int n1, n2;
    for(int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    queue<int> q;
    q.push(1); visit[1] = true;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int i = 0; i < v[cur].size(); i++) {
            int c = v[cur][i];

            if(visit[c]) continue;
            visit[c] = true;
            ans[c] = cur;
            q.push(c);
        }
    }

    for(int i = 2; i <= n; i++) cout << ans[i] << "\n";


    return 0;
}
