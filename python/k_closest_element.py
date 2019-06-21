def find_cross_over(arr, x):
    l = 0
    r = len(arr) - 1
    while(l <= r):
        m =  r + (l-r) // 2
        print(m)
        if(arr[m] <= x and arr[m+1] > x):
            return m
        elif(arr[m] < x):
            l = m + 1
        else:
            r = m - 1

def k_nearest(arr, x, k):
    point = find_cross_over(arr, x)
    count = 0
    le = len(arr) - 1
    l = point
    r = point + 1
    xx = []
    while(count < k and l >= 0 and r <= le):
        if(x - arr[l] < arr[r] - x):
            xx.append(arr[l])
            l -= 1
        else:
            xx.append(arr[r])
            r += 1
        count += 1
    return xx

if __name__ == "__main__":
    arr = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56]
    n = len(arr)
    x = 35
    k = 4
    print(k_nearest(arr, x, k))