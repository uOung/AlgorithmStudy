#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int num[15];
int minV = 0x7f7f7f7f;
int maxV = -0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> num[i];

  int opN = 0;
  vector<int> opV;
  for(int i = 0; i < 4; i++) {
    cin >> opN;
    for(int j = 1; j <= opN; j++) opV.push_back(i);
  }

  do{
    int ans = num[0];
    for(int i = 1; i < n; i++) {
      if(opV[i-1] == 0) ans += num[i];
      else if(opV[i-1] == 1) ans -= num[i];
      else if(opV[i-1] == 2) ans *= num[i];
      else ans /= num[i];

    }

    minV = min(minV, ans);
    maxV = max(maxV, ans);

  } while(next_permutation(opV.begin(), opV.end()));

  cout << maxV << "\n" << minV;

  return 0;
}
