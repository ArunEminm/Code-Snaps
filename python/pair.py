def pair(arr, x):
    s = 0
    e = len(arr) - 1
    pairs = []
    while(s<e):
        xx = arr[s] + arr[e]
        if(xx>x):
            e -= 1
        elif(xx == x):
            pairs.append((arr[s], arr[e]))
            s += 1
        else:
            s += 1
    
    return pairs


def unrotate(arr):
    for i in range(0, len(arr) - 2):
        if(arr[i+1] < arr[i]):
            arr = arr[i+1:] + arr[:i+1]
    return arr


if __name__ == "__main__":
    g = list(map(int, input().rstrip().split()))
    x = int(input())
    arr = unrotate(g)
    print(pair(arr, x))