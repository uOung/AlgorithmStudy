#include <iostream>
#include <algorithm>

using namespace std;

int s[1005];
int d[1005];    // D[i] = i까지 가장 긴 수열의 길이

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> s[i];

    fill(d, d+N, 1);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            if(s[i] > s[j]) d[i] = max(d[i], d[j] + 1);


    cout << *max_element(d, d+N);

    return 0;
}
