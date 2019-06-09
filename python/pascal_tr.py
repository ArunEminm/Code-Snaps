class Solution:
    # @param A : integer
    # @return a list of list of integers
    def solve(self, A):
        C = [[1], [1,1]]
        if(A == 0):
            return ''
        if(A == 1):
            return C[:1]
        if(A == 2):
            return C[:2]
        for i in range(2, A):
            row = [1]
            for j in range(1, i // 2 +1):
                # print(C[i-1])
                row.append(C[i-1][j] + C[i-1][j-1])
            if(i%2 == 1):
                row = row + row[::-1]
            else:
                row = row + row[:-1][::-1]
            C.append(row)
        return C


if __name__ == "__main__":
    print(Solution().solve(5))