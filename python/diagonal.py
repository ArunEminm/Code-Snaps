class Solution:
    # @param A : list of list of integers
    # @return a list of list of integers
    def diagonal(self, A):
        A = len(A[0])
        MAT = []
        for i in range(1, A + 1):
            temp = []
            for j in range(1, A + 1):
                temp.append(A * (i-1) + j)
            MAT.append(temp)

        ret = []
        for i in range(A):
            arr = []
            x, y = 0, i
            arr.append(MAT[x][y])
            while(y != 0):
                x += 1
                y -= 1
                arr.append(MAT[x][y])
            ret.append(arr)
        for i in range(1, A):
            arr = []
            x, y = i, A-1
            arr.append(MAT[x][y])
            while(x != A-1):
                x += 1
                y -= 1
                arr.append(MAT[x][y])
            ret.append(arr)
        return ret


if __name__ == "__main__":
    s = int(input().rstrip())
    print(Solution().diagonal(s))