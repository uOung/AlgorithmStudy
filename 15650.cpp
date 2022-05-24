#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) v.push_back(i < m ? 0 : 1);

    do {
        for(int i = 0; i < n; i++)
            if(v[i] == 0) cout << i + 1 << " ";
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}
