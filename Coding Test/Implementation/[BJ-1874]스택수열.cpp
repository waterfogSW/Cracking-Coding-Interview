#include <bits/stdc++.h>
using namespace std;

vector<char> solution(int n) {
    int arr[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    vector<char> result;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        s.push(i);
        result.push_back('+');

        while (!s.empty() && s.top() == arr[idx]) {
            s.pop();
            result.push_back('-');

            idx++;
        }
    }
    if(!s.empty()) throw std::exception();
    return result;
}

int main() {
    int n;
    cin >> n;
    try {
        for (char c : solution(n)) {
            cout << c << '\n';
        }
    } catch (const std::exception& e) {
        cout << "NO";
    }
}