#include <iostream>

using namespace std;

int A[1000001];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for(int i = 0; i < N; i++) cin >> A[i];

  int B, C;
  cin >> B >> C;

  long long ans = N;  // 총 감독의 수

  for(int i = 0; i < N; i++) {
    A[i] -= B;

    if(A[i]/C > 0) {
      ans += A[i]/C;
      A[i] %= C;
    }

    if(A[i]%C > 0) ans++;
  }

  cout << ans << endl;

  return 0;
}
