def modified_binary(arr, l, r, x):
    while(l <= r):
        m = r + (l - r) // 2
        if(arr[m] == x or (m - 1 >= l and arr[m-1] == x) or (m + 1 <= r and  arr[m+1] == x)):
            return 1
        elif(arr[m] < x):
            l = m + 2
        else:
            r = m - 2
    return -1


if __name__ == "__main__":
    arr = [3, 2, 10, 4, 40]
    print(modified_binary(arr, 0, len(arr) - 1, 4))
    print(modified_binary(arr, 0, len(arr) - 1, 40))
    print(modified_binary(arr, 0, len(arr) - 1, 3))
    print(modified_binary(arr, 0, len(arr) - 1, 55))