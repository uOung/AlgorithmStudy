#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[10];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums, nums + n);

    do {

        for(int i = 0; i < m; i++)
            cout << nums[i] << " ";
        cout << "\n";

        reverse(nums + m, nums + n);

    } while(next_permutation(nums, nums + n));

    return 0;
}
