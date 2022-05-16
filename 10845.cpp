#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(s == "pop") {
            if(!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << -1 << "\n";

        }
        else if(s == "size") cout << q.size() << "\n";
        else if(s == "empty") {
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "front") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }

    }

    return 0;
}
