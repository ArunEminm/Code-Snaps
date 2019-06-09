import math
import sys


class Solution:
    def coverPoints(self, A, B):
        steps = 0
        cx, cy = A[0], B[0]
        for x, y in zip(A, B):
            print(1, x,y)
            print(2, cx, cy)
            if (x, y) != (cx, cy):
                steps += max(abs(x - cx), abs(cy - y))
            cx, cy = x, y
        return steps


if __name__ == "__main__":
    a = list(map(int, input().rstrip().split()))
    b = list(map(int, input().rstrip().split()))
    steps = Solution().coverPoints(a, b)
    print(steps)
