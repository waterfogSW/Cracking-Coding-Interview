#include <bits/stdc++.h>
using namespace std;

class Heap {
   private:
    int heapCount = 0;
    int heapSize;
    int *heap = new int[heapSize];

    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

   public:
    Heap(int size) : heapSize(size) {}

    int size() {
        return heapCount;
    }

    void push(int x) {
        heap[++heapCount] = x;
        int child = heapCount;
        int parent = child / 2;
        while (child > 1 && heap[child] > heap[parent]) {
            swap(&heap[child], &heap[parent]);
            child = parent;
            parent = child / 2;
        }
    }

    int pop() {
        int ret = heap[1];
        swap(&heap[1], &heap[heapCount]);
        heapCount--;

        int parent = 1;
        int child = parent * 2;

        if (child + 1 <= heapCount) {
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }

        while (child <= heapCount && heap[child] > heap[parent]) {
            swap(&heap[child], &heap[parent]);
            parent = child;
            child = parent * 2;

            if (child + 1 <= heapCount) {
                child = (heap[child] > heap[child + 1]) ? child : child + 1;
            }
        }

        return ret;
    }
};

int n;
int main() {
    cin >> n;
    Heap a(2 * n + 1);

    vector<int> result;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if(tmp == 0) {
            if(a.size() == 0) result.push_back(0);
            else result.push_back(a.pop());
        } else {
            a.push(tmp);
        }
    }

    for(int i : result) {
        cout << i << '\n';
    }

    return 0;
}