#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
int arr[20];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> k;
        if(k == 0) break;

        for(int i = 0; i < k; i++) cin >> arr[i];
        sort(arr, arr + k);

        vector<int> v;
        for(int i = 0; i < k; i++) v.push_back(i < 6 ? 0 : 1);

        do {
            for(int i = 0; i < k; i++)
                if(v[i] == 0) cout << arr[i] << " ";
            cout << "\n";

        } while(next_permutation(v.begin(), v.end()));

        cout << "\n";
    }

    return 0;
}
