#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int nums[10];

vector<int> v;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) v.push_back(i < m ? 0 : 1);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums, nums + n);

    do {

        for(int i = 0; i < n; i++)
            if(v[i] == 0) cout << nums[i] << " ";

        cout << "\n";

    } while(next_permutation(v.begin(), v.end()));

    return 0;
}
