class Solution:
    # @param A : list of list of integers
    # @param B : integer
    # @return an integer
    def searchMatrix(self, A, b):
        neA = []
        for i in A:
            neA += i

        mi = 0
        ma = len(neA) - 1

        # print(neA)

        while(mi <= ma):
            m = (mi + ma) // 2
            # print(mi, m, ma)
            if(neA[m] == b):
                return 1
            elif(neA[m] > b):
                ma = m - 1
            else:
                mi = m
        return 0


if __name__ == "__main__":
    m = int(input().rstrip())
    A = []
    for i in range(m):
        A.append(list(map(int, input().rstrip().split(' '))))
    b = int(input().rstrip())
    print(Solution().searchMatrix(A, b))