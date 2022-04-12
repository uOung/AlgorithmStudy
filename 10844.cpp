#include <iostream>

using namespace std;

#define MOD 1000000000

long long d[105][10]; // d[i][j] = i번째 자리의 j가 마지막 숫자일 때 쉬운 계단의 경우의 수

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  // 2자리 -> 1: 10, 12 | 2: 21 23 | 9: 98
  // 3자리(마지막 수) -> 10: 101 | 12: 121, 123 | 21: 210, 212 | 19: 198

  // 예외: 마지막 자리 수가 0 or 9

  // d[2][4] = 2 (34, 54), d[2][6] = 2 (56, 76)
  // d[3][5] = (345, 545, 565, 765)
  // d[p][q] = d[p-1][q-1] + d[p-1][q+1]

  // 초기화
  for(int i = 1; i <= N; i++) d[1][i] = 1;

  d[1][0] = 0;

  for(int p = 2; p <= N; p++) {
    for(int q = 0; q <= 9; q++) {
      if(q == 0) d[p][q] = d[p-1][q+1] % MOD;
      else if(q == 9) d[p][q] = d[p-1][q-1] % MOD;
      else d[p][q] = d[p-1][q-1] + d[p-1][q+1] % MOD;
    }
  }

  long long ans = 0;
  for(int i = 1; i <= 9; i++) ans += d[N][i];

  cout << ans % MOD;

  return 0;
}
