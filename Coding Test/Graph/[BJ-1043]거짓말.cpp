#include <bits/stdc++.h>
using namespace std;

int Find(int x, int *root) {
    if (root[x] == x)
        return x;
    else
        return root[x] = Find(root[x], root);
}

void Union(int x, int y, int *root) {
    x = Find(x, root);
    y = Find(y, root);
    if (x != y) root[y] = x;
}

int solution(int n, int m) {
    int result = m;

    int k;
    cin >> k;

    int *root = new int[n + 1]();
    vector<int> known;  // 진실을 아는 사람의 번호
    auto *party = new int[m]();

    for (int i = 1; i < n + 1; i++) {
        root[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        known.push_back(tmp);
    }

    for (int i = 0; i < m; i++) {
        int l;  // 파티에 오는 사람의 수
        cin >> l;
        int num1;
        cin >> num1;  // 파티 맨앞사람
        party[i] = num1;
        for (int j = 1; j < l; j++) {
            int num;
            cin >> num;
            Union(num1, num, root);
        }
    }

    // 파티의 파티원이 진실을 아는사람 또는 진실을 아는사람과 같은 파티 소속일경우 result--
    for (int i = 0; i < m; i++) {
        for (int j : known)
            if (Find(party[i], root) == Find(j, root)) {
                result--;
                break;
            }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solution(n, m) << '\n';
}
