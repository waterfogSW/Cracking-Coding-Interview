/* 프로그래머스 : 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 타겟 넘버*/
class Solution {
    private int DFS(int[] numbers, int target, int idx) {
        if(idx == numbers.length) {
            if(target == 0) return 1;
            else return 0;
        }
        int tmp = numbers[idx++];
        return DFS(numbers, target + tmp, idx) + DFS(numbers, target - tmp, idx);
        
    }
    public int solution(int[] numbers, int target) {
        int answer = DFS(numbers, target, 0);
        return answer;
    }
}