/* 프로그래머스 : 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 타겟 넘버*/
#include <string>
#include <vector>

using namespace std;

int DFS(vector<int> numbers, int target) {
    if(numbers.size() == 0) {
        if(target == 0) return 1;
        else return 0;
    }
    int tmp = numbers.back();
    numbers.pop_back();
    return DFS(numbers, target + tmp) + DFS(numbers, target - tmp);
}

int solution(vector<int> numbers, int target) {
    int answer = DFS(numbers, target);
    return answer;
}