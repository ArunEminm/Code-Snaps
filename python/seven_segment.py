def big(n):
    arr = {
        '0': 6,
        '1': 2,
        '2': 5,
        '3': 5,
        '4': 4,
        '5': 5,
        '6': 6,
        '7': 3,
        '8': 7,
        '9': 6
    }
    matchsticks = 0
    for i in range(len(n)):
        matchsticks += arr[n[i]]
    if(matchsticks % 2 == 0):
        twos = matchsticks // 2
        return '1' * twos
    else:
        twos = (matchsticks - 3) // 2
        return '7' + '1' * twos


if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        print(big(input()))