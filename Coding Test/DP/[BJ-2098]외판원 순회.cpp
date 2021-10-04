#include <iostream>
#include <vector>
using namespace std;

#define MAX_CITY 16
#define MAX 1000000 * 16

typedef vector<vector<int>> vector2;

// 사이클이 형성되므로 출발도시는 어디가 되었든 상관이 없다

int TSP(int n, int c, int visit, vector2 &dp, vector2 &road) {
    visit |= (1 << c);  // 현재 도시(c) 방문 확인

    if (visit == (1 << n) - 1) {  // 모든 도시에 방문했을 경우
        if (road[c][0] != 0)      // 출발도시(0)로 되돌아가지 못 할 경우
            return road[c][0];
        else
            return MAX;
    }

    if (dp[c][visit] > 0) return dp[c][visit];

    dp[c][visit] = MAX;

    for (int i = 0; i < n; i++) {
        if (i == c || (visit & (1 << i)) != 0 || road[c][i] == 0) continue;

        int tmp = TSP(n, i, visit, dp, road) + road[c][i];
        if (dp[c][visit] > tmp) dp[c][visit] = tmp;
    }

    return dp[c][visit];
}

int Solution(int n) {
    vector2 dp(n, vector<int>(1 << n, 0));
    vector2 road(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> road[i][j];
        }
    }

    int result = TSP(n, 0, 0, dp, road);
    if (result == MAX)
        return -1;
    else
        return result;
}

int main() {
    int n;
    cin >> n;
    cout << Solution(n) << '\n';
}