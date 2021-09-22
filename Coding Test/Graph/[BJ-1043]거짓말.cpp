#include <bits/stdc++.h>
using namespace std;

int Find(int a, int *root) {
    if (root[a] == a)
        return a;
    else
        return root[a] = Find(root[a], root);
}

void Union(int x, int y, int *root) {
    x = Find(x, root);
    y = Find(y, root);
    root[y] = x;
}  // 같은 부모로 연결

int solution(int n, int m) {
    int result = m;
    int *root = new int[n + 1]();
    int *party = new int[m]();

    for (int i = 0; i < n + 1; i++) {
        root[i] = i;
    }

    // 진실을 아는사람들
    int k;
    cin >> k;
    int *known = new int[k]();
    for (int i = 0; i < k; i++) {
        cin >> known[i];
    }

    // 파티 정보 입력
    for (int i = 0; i < m; i++) {
        int l;   // 각 파티에 오는 사람의 수
        cin >> l;
        int num;
        cin >> num;
        party[i] = num; // 파티의 대표자
        for(int j = 1; j < l; j++) {
            cin >> num;
            Union(party[i], num, root);
        }
    }

    // 해당 파티가 거짓말을 할 수 없다면 result--
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            if(Find(party[i], root) == Find(known[j], root)) {
                result--;
                break;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solution(n, m) << '\n';
}