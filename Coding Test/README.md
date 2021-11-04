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

## Union Find(Disjoint Set)



## Topological sorting(위상정렬)
## Spanning Tree
## Segment Tree
## Knapsack Algorithm
## LCS
## LIS