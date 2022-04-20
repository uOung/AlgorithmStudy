#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;    // 짝수

int s[25][25];
int minV = 100;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> s[i][j];

    vector<int> team(n);
    fill(team.begin() + n/2, team.end(), 1);

    do{
        int diff = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(team[i] != team[j]) continue;
                if(team[i] == 0) diff += s[i][j] + s[j][i];
                else diff -= (s[i][j] + s[j][i]);
            }
        }
        minV = min(minV, abs(diff));
    } while(next_permutation(team.begin(), team.end()));

    cout << minV;

    return 0;
}
