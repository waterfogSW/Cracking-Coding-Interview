/* 프로그래머스 : 코딩테스트 연습 > 완전탐색 > 모의고사 */
/* 완전 탐색 문제이나, 핵심은 finding multiple max elements index in vector(list) */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans1 = {1,2,3,4,5};
    vector<int> ans2 = {2,1,2,3,2,4,2,5};
    vector<int> ans3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> cnt = {0,0,0};

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == ans1[i % ans1.size()]) cnt[0]++;
        if(answers[i] == ans2[i % ans2.size()]) cnt[1]++;
        if(answers[i] == ans3[i % ans3.size()]) cnt[2]++;
    }
    auto it = max_element(begin(cnt), end(cnt));
    while (it != end(cnt))
    {
        answer.push_back(distance(begin(cnt), it) + 1);
        it = find(next(it), end(cnt), *it);
    }
    return answer;
}