import sys

class Solution:
    # @param A : list of integers
    # @return a list of integers
    def maxSubArray(self, A):
        # print(A)
        max_ = - sys.maxsize - 1
        s = {}
        for i in range(len(A)):
            for j in range(i, len(A)):
                # print(A[i:j+1])
                s = sum(A[i:j + 1])
                # print(s)
                if(s > max_):
                    max_ = s
        return max_



class Solution:

    def maxSubArray(self, A):
        pass


if __name__ == "__main__":
    s = list(map(int, input().rstrip().split(' ')))
    print(Solution().maxSubArray(s))