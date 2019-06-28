def remove_duplicates(x, v):
    l = len(x)
    shift = 0
    i = 0
    k = 0
    c = 0
    while(i < l):
        if(x[i] == v):
            while(i < l - 1 and x[i + 1] == x[i]):
                i += 1
                c += 1
            while(i + 1 < l and x[i + 1] != v):
                x[k] = x[i + 1]
                # print(x[k], x[i])
                k += 1
                i += 1
            if(i <= l - 1):
                if(x[i] == v):
                    c += 1
                i += 1
        else:
            k += 1
            i += 1
    return l - c


if __name__ == "__main__":
    arr = input().rstrip().rsplit()
    v = input().rstrip()
    print(arr)
    print(remove_duplicates(arr, v))
    print(arr)