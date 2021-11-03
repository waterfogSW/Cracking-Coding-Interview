## Quick Sort
**CPP**
```cpp
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

**java**
```java
static void swap(int[] arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

static int partition(int[] arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
}

static int quickSort(int[] arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, pi - 1);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

```
arr[] = {10, 80, 30, 90, 40, 50, 70}
Indexes:  0   1   2   3   4   5   6 

low = 0, high =  6, pivot = arr[h] = 70
Initialize index of smaller element, i = -1

Traverse elements from j = low to high-1
j = 0 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
i = 0 
arr[] = {10, 80, 30, 90, 40, 50, 70} // No change as i and j 
                                     // are same

j = 1 : Since arr[j] > pivot, do nothing
// No change in i and arr[]

j = 2 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
i = 1
arr[] = {10, 30, 80, 90, 40, 50, 70} // We swap 80 and 30 

j = 3 : Since arr[j] > pivot, do nothing
// No change in i and arr[]

j = 4 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
i = 2
arr[] = {10, 30, 40, 90, 80, 50, 70} // 80 and 40 Swapped
j = 5 : Since arr[j] <= pivot, do i++ and swap arr[i] with arr[j] 
i = 3 
arr[] = {10, 30, 40, 50, 80, 90, 70} // 90 and 50 Swapped 

We come out of loop because j is now equal to high-1.
Finally we place pivot at correct position by swapping
arr[i+1] and arr[high] (or pivot) 
arr[] = {10, 30, 40, 50, 70, 90, 80} // 80 and 70 Swapped 

Now 70 is at its correct place. All elements smaller than
70 are before it and all elements greater than 70 are after
it.
```

## Binary Search(Lower bound, Upper bound)

### Binary Search

**CPP**
```cpp
int binarySearch(vector<int> &arr, int target) {
    int start = 0, end = arr.size();
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
}
```

**java**
```java
static int binarySearch(int[] arr, int n, int target) {
    int start = 0, end = n;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] < target) start = mid + 1;
        else if(arr[mid] > target) end = mid - 1;
        else return mid;
    }
    return -1;
```

### Lower bound

Lower bound는 찾고자 하는 값 이상이 처음 나타나는 위치.
-  target원소가 없거나 여러개 이더라도 상관 없다.

```cpp
int lowerBound(vector<int> &arr, int target) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}
```
### Upper bound

Upper bound는 찾고자 하는 값 초과가 처음 나타나는 위치.

```cpp
int upperBound(vector<int> &arr, int target) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }
}
```

## Dijkstra

```cpp
int Dijkstra(int v, int e,int start, int end) {
    int* dist = new int[v + 1];
    for(int i = 1; i <= v; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    vector<pair<int, int>> graph[v + 1];
    for(int i = 0; i < e; i++) {
        int t1, t2, cost;
        cin >> t1 >> t2 >> cost;
        graph[t1].push_back({t2, cost});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if(dist[cur] < distance) continue;
        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextDist = graph[cur][i].second;

            if(dist[next] > distance + nextDist) {
                dist[next] = distance + nextDist;
                pq.push({-dist[next], next});
            }
        }
    }

    return dist[end];
}
```

Java
```java
    static int Dijkstra(int start, int end) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(start, 0));

        while(!pq.isEmpty()) {
            Edge e = pq.poll();
            int cur = e.dest;
            int curDist = e.cost;

            if(curDist > dist[cur]) continue;
            for(Edge i : graph[cur]) {
                int next = i.dest;
                int nextDist = i.cost;

                if(dist[next] > curDist + nextDist) {
                    dist[next] = curDist + nextDist;
                    pq.add(new Edge(next, dist[next]));
                }
            }
        }

        return dist[end];
    }
```

## Union Find
## Topological sorting(위상정렬)
## Spanning Tree
## Segment Tree

**CPP**
```cpp
#define MAX 10000

int a[MAX];
int tree[MAX * 4]; // Four times can cover all ranges of the array.

// start : start index, end : end index
int init(int start, int end, int node) {
    if (start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) +
                        init(mid + 1, end, node * 2 + 1);
}

// start : start index, end : end index
// left, right : Range that want to find out the sum of
int sum(int start, int end, int node, int left, int right) {
    // Out of range
    if (left > end || right < start) return 0;
    // Within range
    if (left <= start && end <= right) return tree[node];
    // If not, divide it into two parts and find the sum.
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) +
           sum(mid + 1, end, node * 2 + 1, left, right);
}

int update(int start, int end, int node, int index, int val) {
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = val;

	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, index, val) + 
                        update(mid + 1, end, node * 2 + 1, index, val);
}

int main() {
    int n = 5;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    init(0, n - 1, 1);

    cout << "0~2 구간합 : " << sum(0, n - 1, 1, 0, 2) << '\n';
    cout << "2~4 구간합 : " << sum(0, n - 1, 1, 2, 4) << '\n';

    // 3번째 원소 업데이트 
    update(0, n - 1, 1, 2, 7);
    cout << "0~2 구간합 : " << sum(0, n - 1, 1, 0, 2) << '\n';
    cout << "2~4 구간합 : " << sum(0, n - 1, 1, 2, 4) << '\n';
}
```

## Indexed Tree(Fenwick Tree)
```cpp
#include <iostream>
using namespace std;

typedef long long ll;

void swap(int *b, int *c) {
    int temp = *b;
    *b = *c;
    *c = temp;
}

void update(int i, int dif, int n, ll *tree) {
    while (i <= n + 1) {
        tree[i] += dif;
        i += (i & -i);
    }
}

ll sum(int i, ll *tree) {
    ll result = 0;
    while (i > 0) {
        result += tree[i];
        i -= (i & -i);
    }
    return result;
}

ll getSection(int start, int end, ll *tree) {
    return sum(end, tree) - sum(start - 1, tree);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    ll *arr = new ll[n + 1]();
    ll *tree = new ll[n + 1]();

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (a == 0) {
            if (b > c) swap(b, c);
            cout << getSection(b, c, tree) << '\n';
        } else {
            ll temp = c - arr[b];
            arr[b] = c;
            update(b, temp, n, tree);
        }
    }
}
```
## Knapsack Algorithm
## LCS
## LIS