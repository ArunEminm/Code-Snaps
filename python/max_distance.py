import sys

class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maximumGap(self, A):
        arr = []
        for i in range(len(A)):
            arr.append((i, A[i]))
        arr = sorted(arr, key=lambda x: x[1])
        m = 0
        diff = 0
        for i in range(len(arr)-1, 0, -1):
            m = max(m, arr[i][0])
            diff = m - arr[i][0]
        return diff



if __name__ == "__main__":
    s = list(map(int, input().rstrip().split()))
    print(Solution().maximumGap(s))