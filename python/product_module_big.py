def find_p(arr):
    num = 1000000000 + 7
    mul = 1
    for i in arr:
        mul = (mul * i) % num
    return mul

if __name__ == "__main__":
    t = int(input())
    print(find_p(map(int, input().rstrip().split(' '))))