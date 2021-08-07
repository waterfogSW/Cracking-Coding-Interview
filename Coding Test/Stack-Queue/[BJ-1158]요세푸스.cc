#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    cout << '<';

    int index = 1;
    while(q.size() > 1) {
        if(index % k != 0) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        } else {
            cout << q.front() << ", ";
            q.pop();
        }
        index++;
    }
    cout << q.front(); 
    cout << '>';
}