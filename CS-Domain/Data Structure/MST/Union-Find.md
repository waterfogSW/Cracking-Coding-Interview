#최소신장트리

```c++
#include <bits/stdc++.h>
using namespace std;

int Find(int a, int *arr) {
    if (arr[a] == a)
        return a;
    else
        return Find(arr[a], arr);
}

void Union(int x, int y, int *arr) {
    x = Find(x, arr);
    y = Find(y, arr);
    if (x <= y) {
        arr[y] = x;
    } else {
        arr[x] = y;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    int *root = new int[e + 1];
    for (int i = 1; i <= e; i++) {
        root[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b, root);
    }

    for (int i = 1; i <= e; i++) {
        cout << root[i] << ' ';
    }
}
```