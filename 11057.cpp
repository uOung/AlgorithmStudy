#include <iostream>

using namespace std;

#define MOD 10007

int d[1005][10];  // d[i][j] = i자리 수의 j가 마지막 자리 수인 경우의 수

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  // d[1][0] = 1(0) | d[1][1] = 1(1) | d[1][2] = 1(2)
  // d[2][0] = 1(00) | d[2][1] = 2(01, 11) | d[2][2] = 3(02, 12, 22) | d[2][3] = 4(03, 13, 23, 33) | d[2][4] = 5(04, 14, 24, 34, 44)
  // d[3][0] = 1(000) | d[3][1] = 3(001, 011, 111)

  for(int i = 1; i <= n; i++) {
    d[i][0] = 1;
    for(int j = 1; j <= 9; j++) {
      d[i][j] = (d[i][j-1] + d[i-1][j]) % MOD;
    }
  }

  long long ans = 0;
  for(int i = 0; i <= 9; i++) ans += d[n][i];

  cout << ans % MOD;

  return 0;
}
