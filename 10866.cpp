#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> dq;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(s == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(s == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else cout << -1 << "\n";

        }
        else if(s == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else cout << -1 << "\n";

        }
        else if(s == "size") cout << dq.size() << "\n";
        else if(s == "empty") {
            if(dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "front") {
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else {
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }

    }

    return 0;
}
