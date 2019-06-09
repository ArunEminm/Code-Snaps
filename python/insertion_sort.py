#!/bin/python3

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while (j >= 0 and arr[j] > arr[j + 1]):
            arr[j], arr[j+1] = arr[j+1], arr[j]
            j -= 1
    return arr

if __name__ == "__main__":
    arr = map(int, raw_input().rstrip().split(' '))
    print(arr)
    insertion_sort(arr)
    print(arr)