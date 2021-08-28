#include <bits/stdc++.h>
using namespace std;

int n, res;
long long s;
int main() {
    cin >> s;

    for (int i = 1; i <= s; i++) {
        s -= i;
        res++;
        if (s < 0) res--;
    }

    cout << res;
}