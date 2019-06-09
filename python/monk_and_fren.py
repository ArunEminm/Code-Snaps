class Node:
    def __init__(self, val=None, left = None, right = None):
        self.val = val
        self.right = right
        self.left = left

    def insert(self, val):
        h = 0
        if(not self.val):
            self.val = val
            h = 1
        else:
            cn = self
            while(cn.val):
                if (cn.val >= val):
                    if(cn.left):
                        cn = cn.left
                    else:
                        cn.left = Node()
                else:
                    if(cn.right):
                        cn = cn.right
                    else:
                        cn.right = Node()
                h += 1
            cn.val = val
        return h
    
    def search(self, val):
        cn = self
        while(cn):
            if(cn.val == val):
                return 'YES'
            elif(val <= cn.val):
                cn = cn.left
            else:
                cn = cn.right
        return 'NO'
    
    # def height(self):
    #     if(self.val):
    #         return 1 + max(
    #             self.left.height() if self.left else 0,
    #             self.right.height() if self.right else 0
    #         )


if __name__ == "__main__":
    l = int(input())
    for i in range(l):
        n,m = list(map(int, input().rstrip().split()))
        s = list(map(int, input().rstrip().split()))
        d = {}
        # b = Node()
        for i in range(n):
            d[s[i]] = True
        for i in range(n, n + m):
            if s[i] in d:
                print('YES')
            else:
                print('NO')
                d[s[i]] = True
        