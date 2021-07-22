#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> req;
int limit;

int sol(vector<int> &a, int limit) {  // limit = mid
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i] > limit) {
            sum += limit;
        } else {
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    cin >> n;
    int sum = 0;
    // 예산 요청
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        //sum += temp;
        req.push_back(temp);
    }
    cin >> limit;
    
    sort(req.begin(), req.end());

    int start = 0;
    int end = req[req.size()-1];
    int result = 0;

    while(start<=end){
        int mid = (start+end)/2;

        int _sum = sol(req, mid);

        // 최적해
        // 이분탐색 조건
        if(_sum > limit){   // 조건 불충족
             end = mid - 1;
        } else{ // 조건 충족
            start = mid + 1;
            result = mid;
        }

    }

    cout << result << '\n'; 

    
}

// 지방 예산 a b c 



    // sort(req.begin(), req.end());
    // if (sum > limit) { // 전체 요청금액이 예산을 넘은경우
    //     // 특정 금액에서 (총합 - 예산) - (상한 총합 - 예산)이전금액보다 작거나 같은경우 해당금액을 상한액으로
    //     int start = 0;
    //     int end = req[req.size() -1];
    //     int mid;
    //     //int temp1 = 0; 
    //     int temp2 = 0;
    //     int result = 0;

    //     while (start <= end) {
    //         mid = (start + end) / 2;
    //         temp2 = sol(req, mid);
    //         if(temp2 <= limit) {  // 조건 충족 + 상한선 높일 수 있음.
    //             start = mid + 1;
    //             result = mid;
    //         } else {  // 조건 불충족
    //             end = mid - 1;
    //         }
    //         //temp1 = temp2;
    //     }

    //     cout << result;
    // } else { // 전체 요청금액이 예산을 넘지 않은경우
    //     int _max = 0;
    //     for (int i = 0; i < n; i++) { 
    //         _max = max(_max, req[i]);
    //     }
    //     cout << _max;
    // }