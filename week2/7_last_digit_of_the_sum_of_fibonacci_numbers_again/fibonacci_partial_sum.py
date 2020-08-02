# Uses python3
import sys

PISANO = 60
 
 
def solution(left, right):
    assert not left > right  # 1
 
    fib_mods = [0, 1]  # 2
    for _ in range(PISANO - 2):
        fib_mods.append((fib_mods[-1] + fib_mods[-2]) % 10)
 
    left %= PISANO  # 3
    right %= PISANO
    if right < left:
        right += PISANO
 
    result = 0
    for i in range(left, right + 1):
        result += fib_mods[i % PISANO]  # 4
    return result % 10  # 5

def fibonacci_partial_sum_naive(from_, to):
    sum = 0

    current = 0
    next  = 1

    for i in range(to + 1):
        if i >= from_:
            sum += current

        current, next = next, current + next

    return sum % 10


if __name__ == '__main__':
    #input = sys.stdin.read();
    inp = input()
    from_, to = map(int, inp.split())
    #print(fibonacci_partial_sum_naive(from_, to))
    print(solution(from_, to))