#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) v.push_back(i);

    do {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

        reverse(v.begin() + m, v.end());

    } while(next_permutation(v.begin(), v.end()));

    return 0;
}
