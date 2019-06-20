class Node:

    def __init__(self, val, next=None):
        self.val = val
        self.next = next



class LinkedList:

    def __init__(self):
        self.head = None

    def add_in_front(self, v):
        no = Node(v)
        no.next = self.head
        self.head = no
    
    def add(self, v):
        self.add_in_front(v)
    
    def print(self):
        c = []
        cc = self.head
        while(cc):
            c.append(cc.val)
            cc = cc.next
        print(c)
    
    def merge(self, l2):
        c1 = self.head
        c2 = l2.head
        r = 0
        while(c1 and c2):
            
            if(r % 2 == 0):
                n = c2.next
                t = c1.next
                c1.next = c2
                c2.next = t
                c2 = n
            c1 = c1.next
            r += 1
        
        l2.head = c2
        return self, l2
        


if __name__ == "__main__":
    l1 = '1269'
    l2 = '1324434'

    L1 = LinkedList()
    for i in reversed(list(l1)):
        L1.add(int(i))

    L2 = LinkedList()
    for i in reversed(list(l2)):
        L2.add(int(i))
    
    l1, l2 = L1.merge(L2)
    l1.print()
    l2.print()