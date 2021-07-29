#include <bits/stdc++.h>
using namespace std;

int n;
char p_node, lc_node, rc_node;

struct node {
    char left;
    char right;
};

struct node arr[27];

void preOrder(char root) {
    if(root == '.') return;
    cout << root;
    preOrder(arr[root].left);
    preOrder(arr[root].right);
}

void inOrder(char root) {
    if(root == '.') return;
    inOrder(arr[root].left);
    cout << root;
    inOrder(arr[root].right);
}

void postOrder(char root) {
    if(root == '.') return;
    postOrder(arr[root].left);
    postOrder(arr[root].right);
    cout << root;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p_node >> lc_node >> rc_node;
        arr[p_node].left = lc_node;
        arr[p_node].right = rc_node;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";
}