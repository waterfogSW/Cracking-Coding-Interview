# 프로그래머스 : 코딩테스트 연습 > 완전탐색 > 모의고사
# 완전 탐색 문제이나, 핵심은 finding multiple max elements index in list
# enumerate를 통해 인덱스 출력을 간단히 할 수 있음
def solution(answers):
    ans1 = [1,2,3,4,5]
    ans2 = [2,1,2,3,2,4,2,5]
    ans3 = [3,3,1,1,2,2,4,4,5,5]
    cnt = [0,0,0]
    
    for i in range(len(answers)):
        if answers[i] == ans1[i % len(ans1)] : cnt[0] = cnt[0] + 1
        if answers[i] == ans2[i % len(ans2)] : cnt[1] = cnt[1] + 1
        if answers[i] == ans3[i % len(ans3)] : cnt[2] = cnt[2] + 1
    
    return [i+1 for i, x in enumerate(cnt) if x == max(cnt)]