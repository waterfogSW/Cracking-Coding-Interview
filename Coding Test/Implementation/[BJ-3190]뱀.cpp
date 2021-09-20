#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[101][101];
queue<pair<int, char>> chg;
queue<pair<int, int>> history;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isInside(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) return false;
    return true;
}

int solution() {
    int sec = 0;
    int hd = 0, td = 0;  // 머리, 꼬리 방향
    int hx = 1, hy = 1;  // 머리 위치
    int tx = 1, ty = 1;  // 꼬리 위치
    int len = 0;         // 몸의 길이

    while (1) {
        if (!chg.empty() && chg.front().first == sec) {
            char cdir = chg.front().second;
            if (cdir == 'D') {
                hd = (hd + 1) % 4;
                history.push({sec, hd});
            }
            if (cdir == 'L') {
                hd = (hd - 1 + 4) % 4;
                history.push({sec, hd});
            }
            chg.pop();
        }

        hx += dx[hd];
        hy += dy[hd];
        if (!isInside(hx, hy) || board[hx][hy] == 1) break;
        if (board[hx][hy] != 2) {
            if (!history.empty() && history.front().first == sec - len) {
                td = history.front().second;
                history.pop();
            }
            board[tx][ty] = 0;  // 사과가 없다면 꼬리를 하나 이동
            tx += dx[td];
            ty += dy[td];
        } else if(board[hx][hy] == 2) {
            len++;
        }
        board[hx][hy] = 1;
        sec++;
    }
    return sec + 1;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;  // 사과위치
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        chg.push({x, c});
    }

    board[1][1] = 1;

    cout << solution() << '\n';
}