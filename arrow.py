import sys


def check_hp(N, hp):
    pos = 0
    for i in range(N):
        if hp[i] > 0:
            pos = i
            return False, pos
    return True, pos


def test(N, K, M, X, hp):
    pos = 0
    for i in range(K):
        max_damage = M * X
        all_destroyed = True
        for j in range(N):
            distance = (pos - j) ** 2
            if max_damage >= distance:
                hp[j] -= max_damage - distance

        flag, pos = check_hp(N, hp)
        if flag:
            return True

    return False


def find_X(N, M, K, hp):
    low = 1
    high = max(hp) * 10

    print("Multipliers:", M)
    print("原本的high and pos:", max(hp), hp.index(max(hp)))
    print("Last pos hp:", hp[-1], hp.index(hp[-1]))

    ans = high
    while low <= high:
        mid = (low + high) // 2
        hp_copy = hp.copy()
        if test(N, K, M, mid, hp_copy):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
        # print("low, high, mid:", low, high, mid)

    return ans


sys.stdin = open("in", "r")
# sys.stdout = open("out", "w")

N, M, K = map(int, input().split())
hp = list(map(int, input().split()))

print(find_X(N, M, K, hp))
