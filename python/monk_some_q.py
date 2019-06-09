import collections
import sys


class DS:

    def __init__(self):
        self.d = collections.defaultdict(int)
        self.max = -sys.maxsize - 1
        self.min = sys.maxsize

    def insert(self, val):
        if(val not in self.d):
            self.d[val] += 1
        if(val < self.min):
            self.min = val
        if(val > self.max):
            self.max = val

    def recalculate(self):
        mi = sys.maxsize
        ma = -sys.maxsize - 1
        for k, v in self.d.items():
            if mi > k:
                mi = k
            if ma < k:
                ma = k
        self.max = ma
        self.min = mi

    def delete(self, val):
        if(val in self.d):
            self.d[val] -= 1
            if(self.d[val] == 0):
                del self.d[val]
                self.recalculate()
            return 0
        else:
            return -1

if __name__ == "__main__":
    q = int(input())
    ds = DS()
    for i in range(q):
        s = list(map(int, input().rstrip().split()))
        if(s[0] == 1):
            ds.insert(s[1])
        elif(s[0] == 2):
            kk = ds.delete(s[1])
            if kk == -1:
                print(-1)
        elif(s[0] == 3):
            print(ds.max)
        else:
            print(ds.min)

