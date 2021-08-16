#include <bits/stdc++.h>
using namespace std;

int pay;
int res;

int changes[6] = {500, 100, 50, 10, 5, 1};

int main() {
    cin >> pay;
    pay = 1000 - pay;
    for (int change : changes) {
        int cnt = 0;
        if (pay >= change) {
            res += cnt = pay / change;
            pay -= change * cnt;
        }
    }

    cout << res;
}