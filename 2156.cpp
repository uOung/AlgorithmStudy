#include <iostream>

using namespace std;

int d[10005][3];  // d[i][j] = i번째 잔에서 j(1 or 2)번째 포도주를 마셨을 때 최대 포도주 양
int p[10005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++) cin >> p[i];

  // d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]}) : i번째 잔은 마시지 않을 때
  // d[i][1] = d[i-1][0] + p[i] : i번째 잔이 1번째 잔이며 마실 때
  // d[i][2] = d[i-1][1] + p[i] : i번째 잔이 2번째 잔이며 마실 때

  d[1][1] = p[1];

  for(int i = 1; i <= n; i++){
    d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
    d[i][1] = d[i-1][0] + p[i];
    d[i][2] = d[i-1][1] + p[i];
  }

  cout << max(d[n][0], max(d[n][1], d[n][2]));

  return 0;
}
