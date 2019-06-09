def __cc(a, b, c):
    if(b-a == 0):
        return 0
    elif(b % c == 0):
        return c//b
    elif((a-b) % 2 == 0 ):
        return (a-b) // 2

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        a, b, c = list(map(int, input().rstrip().split(' ')))
        print(__cc(a,b,c))