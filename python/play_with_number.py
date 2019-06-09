import math

def ff(arr, fr, to):
    base = to - fr + 1
    av = 0
    for i in range(fr, to):
        av += arr[i] / base
    return math.floor(av)


if __name__ == "__main__":
    _, t = map(int, input().rstrip().split())

    arr = list(map(int, input().rstrip().split()))

    for i in range(t):
        fr, to = list(map(int, input().rstrip().split()))
        print(arr, fr, to)
        print(ff(arr, fr, to))