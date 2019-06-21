import sys


def get_closest(arr, X):
    l = 0
    diff = sys.maxsize
    r = len(arr) - 1

    while(l < r):
        _diff = arr[l] + arr[r] - X
        if abs(_diff) < diff:
            diff = abs(_diff)
            result = arr[l], arr[r]
        elif _diff < 0:
            l += 1
        else:
            r -= 1
    

    return result



if __name__ == "__main__":
    l = [10, 22, 28, 29, 30, 40]
    print(get_closest(l, 54))