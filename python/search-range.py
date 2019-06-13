def binary_search(arr, l, r, k):
    index = []
    while(l <= r):
        m = (l+r) // 2
        if(arr[m] == k):
            k = m
            # print(m)
            index.append(k)
            i = m + 1
            while(i < len(arr) and arr[i] == arr[m]):
                # print('l', i)
                index.append(i)
                i += 1
            i = m - 1
            while(i > -1 and arr[i] == arr[m]):
                # print('m', i)
                index.insert(0, i)
                i -= 1
            break
        elif(k > arr[m]):
            l = m + 1
        else:
            r = m - 1
    return index

class Solution:

    def searchRange(self, nums, target):
        index = binary_search(nums, 0, len(nums) - 1, target)
        print(index)
        if(index == []):
            return [-1, -1]
        elif(len(index) == 1):
            return [index[0], index[0]]
        else:
            return [index[0], index[-1]]



if __name__ == "__main__":
    nums = [1,2,3]
    target = 2
    print(Solution().searchRange(nums, target))
        