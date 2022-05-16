#include <iostream>
#include <stack>

using namespace std;

char set[2] = { ')', ']'};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        string s;
        getline(cin, s);
        if(s == ".") break;

        stack<int> st;
        bool balance = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') st.push(0);
            else if(s[i] == '[') st.push(1);

            if(s[i] == ')' || s[i] == ']') {
                if(st.empty() || set[st.top()] != s[i]) {
                    cout << "no\n";
                    balance = false;
                    break;
                }
                st.pop();
            }
        }

        if(!balance) continue;

        if(!st.empty()) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}
