def binary_search(arr, l, r, k):
    while(l <= r):
        m = (l+r) // 2
        if(arr[m] == k):
            return m
        elif(k > arr[m]):
            l = m + 1
        else:
            r = m - 1
    return -1


def get_pivot(arr, l = 1, r = None):
    l = l or 1
    r = r or len(arr) - 2
    m = (l + r) // 2
    if(l == m or m == r):
        return None
    if(arr[m - 1] < arr[m] and arr[m] > arr[m + 1]):
        return m
    else:
        ll = None
        if((l, m) != (l, r)):
            ll = get_pivot(arr, l, m)
        if ll is None:
            if((m, r) != (l, r)):
                return get_pivot(arr, m, r)
            else:
                return None
        else:
            return ll


class Solution:

    def search(self, nums, target):
        l = nums
        p = get_pivot(l)
        k = target
        if(k >= l[0]):
            x = binary_search(l, 0, p, k)
        else:
            x = binary_search(l, p + 1, len(l) - 1 , k)
        return x

        

if __name__ == "__main__":
    l  = []
    p = get_pivot(l)
    k = 4
    if(k >= l[0]):
        print(binary_search(l, 0, p, k))
    else:
        print(binary_search(l, p + 1, len(l) - 1 , k))