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

    def __add__(self, l2):
        s1 = []
        s2 = []
        c1 = self.head
        c2 = l2.head

        while(c1 or c2):
            if(c1):
                s1.append(c1.val)
                c1 = c1.next
            if(c2):
                s2.append(c2.val)
                c2 = c2.next

        l3 = LinkedList()
        
        l1s = len(s1)
        l2s = len(s2)
        print(l1s, l2s)
        carry = 0
        if l2s > l1s:
            s2, s1 = s1, s2
        print(s1, s2)
        while(len(s2) > 0):
            c = s1.pop()
            s = c + s2.pop() + carry
            carry = s // 10
            n = s % 10
            l3.add(n)
        while(len(s1) > 0):
            c = s1.pop()
            s = c + carry
            carry = s // 10
            n = s % 10
            l3.add(n)
        return l3
            

if __name__ == "__main__":
    l1 = '1269'
    l2 = '1324434'

    L1 = LinkedList()
    for i in reversed(list(l1)):
        L1.add(int(i))

    L2 = LinkedList()
    for i in reversed(list(l2)):
        L2.add(int(i))
    L1.print()
    L2.print()
    L3 = L1 + L2
    L3.print()