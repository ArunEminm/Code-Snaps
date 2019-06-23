def remove_duplicates(x):
    i = 0
    l = len(x)
    k = 0
    while(i < l and k < l):
        c = x[i]
        print(i, k, c)
        while(i < l - 1 and x[i + 1] == x[i]):
            i = i + 1
            print('x', i)
        x[k] = c
        k = k + 1
        print('k', i)
    return k + 1

if __name__ == "__main__":
    arr = input().rstrip().rsplit()
    print(arr)
    print(remove_duplicates(arr))
    print(arr)