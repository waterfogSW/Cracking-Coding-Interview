#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if(temp == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if(temp == "pop") {
            if(q.size() == 0) cout << "-1" << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if(temp == "size") {
            cout << q.size() << "\n";
        } else if(temp == "empty") {
            cout << int(q.empty()) << "\n";
        } else if(temp == "front") {
            if(q.size() == 0) cout << "-1" << "\n";
            else cout << q.front() << "\n";
        } else if(temp == "back") {
            if(q.size() == 0) cout << "-1" << "\n";
            else cout << q.back() << "\n";
        }
    }
    
}