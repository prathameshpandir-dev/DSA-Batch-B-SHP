#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main() {
    string s, ans = "";
    stack<char> st;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (isalnum(ch))
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   (priority(st.top()) > priority(ch) ||
                   (priority(st.top()) == priority(ch) && ch != '^'))) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;

    return 0;
}
