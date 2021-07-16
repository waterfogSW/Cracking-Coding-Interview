#include <bits/stdc++.h>
using namespace std;

int n, target;
vector<int> arr;

inline int binarySearch(vector<int>& arr, int target, int start, int end) {
    int mid = (start + end)/2;
    if(arr[mid] == target) return mid;
    if(target > mid) return binarySearch(arr,target, mid+1, end);
    else return binarySearch(arr,target, start, mid);
}

int binarySearch2(vector<int>& arr, int target, int start, int end){
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == target)
            return mid;

        else if(arr[mid] > target)
            end = mid -1;
        else
            start = mid+1;
    }
    return -1;
}

int binarySearch3(vector<int>& arr, int target, int start, int end) {
    int _start = start;
    int _end = end;
    int mid = 0;

    while(1) {
        mid = (_start + _end) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) _start = mid + 1;
        else _end = mid;
    }
    return -1;
}

int main(void) {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int result = binarySearch3(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "not found" << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}