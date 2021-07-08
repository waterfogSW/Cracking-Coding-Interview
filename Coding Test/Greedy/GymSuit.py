# 코딩테스트 연습 > 탐욕법(Greedy) > 체육복
## Solution 1
def solution1(n, lost, reserve):
    for i in reserve[:]:
        if i in lost:
            reserve.remove(i)
            lost.remove(i)
    
    for i in lost[:]:
        if i-1 in reserve:
            reserve.remove(i-1)
            lost.remove(i)
        elif i+1 in reserve:
            reserve.remove(i+1)
            lost.remove(i)
    return n - len(lost)

# for i in list[:] -> list를 모두 복사한 후 순회
# for i in list: -> list를 복사하지 않고 순회
# for문 내에 remove가 존재하는 경우 조심

## Solution 2(list comprehension or set)
def solution2(n, lost, reserve):
    # _reserve = [i for i in reserve if i not in lost]
    # _lost = [i for i in lost if i not in reserve]
    
    _reserve = list(set(reserve) - set(lost))
    _lost = list(set(lost) - set(reserve))
    
    for i in _reserve:
        if i-1 in _lost:
            _lost.remove(i-1)
        elif i+1 in _lost:
            _lost.remove(i+1)
    return n - len(_lost)