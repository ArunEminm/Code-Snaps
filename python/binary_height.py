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
    
    # def height(self):
    #     if(self.val):
    #         return 1 + max(
    #             self.left.height() if self.left else 0,
    #             self.right.height() if self.right else 0
    #         )


if __name__ == "__main__":
    l = input()
    s = list(map(int, input().rstrip().split()))
    n = Node()
    ma = 1
    for i in s:
        h = n.insert(i)
        if(ma < h):
            ma = h
    print(ma)