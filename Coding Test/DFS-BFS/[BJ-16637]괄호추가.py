from sys import exit

class Solution:
    def __init__(self, _n, _exp):
        self.n = _n
        self.exp = _exp
        self.max_ans = -9999

    def cal(self, i1, i2, op):
        result = i1
        if      op == '+' : result += i2
        elif    op == '-' : result -= i2
        elif    op == '*' : result *= i2
        else : exit()
        return result

    def recur(self, idx, cur):
        if idx > self.n-1:
            self.max_ans = max(self.max_ans, cur)
            return
        oper = '+' if idx == 0 else self.exp[idx - 1]

        if idx + 2 < self.n :
            bracket = self.cal(int(self.exp[idx]), int(self.exp[idx + 2]), self.exp[idx + 1])
            self.recur(idx + 4, self.cal(cur, bracket, oper))

        self.recur(idx + 2, self.cal(cur, int(self.exp[idx]), oper))

def main():
    n, exp = input(), input()
    
    s = Solution(int(n),exp)
    s.recur(0,0)

    print(s.max_ans)

if __name__ == "__main__":
    main()