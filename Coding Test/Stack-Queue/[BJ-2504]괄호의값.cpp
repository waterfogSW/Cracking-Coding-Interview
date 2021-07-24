#include <bits/stdc++.h>
using namespace std;

string temp;
stack<char> par;
int main() {
    cin >> temp;

    int acc = 1;
    int result = 0;
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == '(') {
            acc *= 2;
            par.push(temp[i]);
        }
        if (temp[i] == '[') {
            acc *= 3;
            par.push(temp[i]);
        }
        if (temp[i] == ')' && (par.empty() || par.top() != '(')) {
            cout << '0' << '\n';
            return 0;
        }
        if (temp[i] == ']' && (par.empty() || par.top() != '[')) {
            cout << '0' << '\n';
            return 0;
        }
        if (temp[i] == ')') {
            if (temp[i - 1] == '(') result += acc;
            acc /= 2;
            par.pop();
        }
        if (temp[i] == ']') {
            if (temp[i - 1] == '[') result += acc;
            acc /= 3;
            par.pop();
        }
    }

    if (!par.empty()) {
        cout << '0' << '\n';
    } else {
        cout << result << '\n';
    }
    return 0;
}