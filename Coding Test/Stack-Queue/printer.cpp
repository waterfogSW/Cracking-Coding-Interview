/* 프로그래머스 : 코딩테스트 연습 > 스택/큐 > 프린터*/
/* 큐를 활용한 문제, 가장 우선순위가 높은 값을 매번 확인하는 대신 우선순위 큐를 활용 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i = 0; i< priorities.size(); i++) {
        q.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!pq.empty()) {
        int index = q.front().first;
        int prior = q.front().second;
        
        q.pop();
        if(prior == pq.top()) {
            pq.pop();
            answer += 1;
            if(index == location) break;
        } else {
            q.push(make_pair(index, prior));
        }
    }
    return answer;
}