// BFS가 아닌 이유는 모든 경우의 수를 찾아야하기 때문에 DFS로 풀어야 한다.
// 최종 풀이
#include <bits/stdc++.h>
using namespace std;

int n;
int chess[15];

bool promis(int r_idx) {
    for (int i = 0; i < r_idx; i++) {
        int temp = chess[r_idx];
        if (temp == chess[i] || r_idx - i == abs(temp - chess[i])) {
            return 0;
        }
    }
    return true;
}

int dfs(int r_idx) {
    // 종료조건
    if (r_idx == n) return 1;

    // 반환할 값
    int result = 0;
    
    // 조건 만족하는 경로 찾기
    for (int i = 0; i < n; i++) {
        chess[r_idx] = i;
        if(promis(r_idx)) 
            result += dfs(r_idx + 1);
    }
    return result;
}

int main() {
    cin >> n;
    cout << dfs(0);
}

// 첫 풀이

// #include <bits/stdc++.h>
// using namespace std;

// int n;

// bool _promis(vector<int> &chess) {
//     if(chess.size() == 0) return true;
    
//     int cur = chess.back();
//     for (int i = 1; i < chess.size(); i++) {
//         int temp = chess[chess.size() - 1 - i];
//         if(temp == cur - i || temp == cur + i || temp == cur) return false;
//     }
    
//     return true;
// }

// int dfs(vector<int> &chess) {
//     if (chess.size() == n) return 1;

//     int result = 0;
//     for (int i = 1; i <= n; i++) {
//         chess.push_back(i);
//         if (_promis(chess)) {
//             result += dfs(chess);
//         }
//         chess.pop_back();
//     }
//     return result;
// }

// int main() {
//     cin >> n;
//     vector<int> chess;

//     cout << dfs(chess);
// }