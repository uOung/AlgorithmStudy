#include <iostream>

using namespace std;

int n = 10;
int arr[] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

// arr[st:en] 정렬
void quick_sort(int st, int en) {
    if(st + 1 >= en) return;    // base condition: 배열의 길이가 1이하이면 함수 종료

    int pivot = arr[st];
    int l = st + 1, r = en - 1;

    while(1) {
        while(l <= r && arr[l] <= pivot) l++;
        while(l <= r && arr[r] >= pivot) r--;

        if(l > r) break;    // l과 r이 역전되는 즉시 탈출
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);

    quick_sort(st, r);
    quick_sort(r + 1, en);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    quick_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
