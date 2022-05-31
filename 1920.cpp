#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100005];

int binarySearch(int num) {
    int start = 0, end = n - 1;

    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] < num) start = mid + 1;
        else if(arr[mid] > num) end = mid - 1;
        else return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int num;
    cin >> m;
    while(m--) {
        cin >> num;
        cout << binarySearch(num) << "\n";
    }

    return 0;
}
