class Solution:
    # @param A : integer
    # @return an integer
    def reverse(self, A):
        ma = pow(2, 31) - 1
        mi = -pow(2, 31) -1
        def _is32(A):
            if(A < mi):
                return 0
            elif(A > ma):
                return 0
            return 1
        if(not _is32(A)):
            return 0
        elif(A > 0):
            new = int(str(A)[::-1])
            if(not _is32(new)):
                return 0
            return str(new)
        else:
            new = int(str(A * -1)[::-1])
            if(not _is32(new)):
                return 0
            return '-%s' % str(new)

if __name__ == "__main__":
    print(Solution().reverse(-1146467285))