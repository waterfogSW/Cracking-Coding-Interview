#include <bits/stdc++.h>

using namespace std;

string vps(string _str) {
    // 왼쪽괄호 1개 + 오른쪽 괄호 1개
    vector<char> _stack;
    for(char c: _str) {
        if(_stack.size() == 0) {
            _stack.push_back(c);
            continue;
        }
        if(_stack.back() == '(' && c == ')') _stack.pop_back();
        else _stack.push_back(c);
    }
    if(_stack.size() > 0) return "NO";
    else return "YES";
}

int n;
int main() {
    cin >> n;
    string par[n];
    for (int i = 0; i < n; i++) {
        cin >> par[i];
    }
    for (int i = 0; i < n; i++) {
        cout << vps(par[i]) << '\n';
    }
    
}

