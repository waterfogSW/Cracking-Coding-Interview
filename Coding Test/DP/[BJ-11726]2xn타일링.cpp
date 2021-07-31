#include <bits/stdc++.h>

using namespace std;
int n;
int rec[1001];
int main() {
    int n;
    cin >> n;

    rec[1] = 1;
    rec[2] = 2;

    for (int i = 3; i <= n; i++) {
        rec[i] = (rec[i - 1] + rec[i - 2]) % 10007; 
        // 올라가는 패턴은 같고 결국 나머지값을 출력해야 하므로 dp구하는 단계부터 모듈러 연산(overflow방지)
    }

    cout << rec[n];

    return 0;
}