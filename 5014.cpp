#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int f, s, g, u, d;
int arr[1000005];

queue<int> q;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    fill(arr, arr + 1000005, -1);

    arr[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(auto nxt : {cur + u, cur - d}) {
            if(nxt > f || nxt < 1 || arr[nxt] != -1) continue;
            arr[nxt] = arr[cur] + 1;
            q.push(nxt);
        }
    }

    if(arr[g] == -1) cout << "use the stairs";
    else cout << arr[g];

    return 0;
}
