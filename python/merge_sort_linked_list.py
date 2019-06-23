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
    
    def print_tail(self, c):
        s = []
        while(c):
            s.append(c.val)
            c = c.next
        print(s)

    def split(self, c):
        slow = c
        fast = c
        while(fast):
            fast = fast.next
            if(fast):
                fast = fast.next
                slow = slow.next

        nex = slow
        slow.next = None
        self.print_tail(nex)
        self.print_tail(self.head)
        return self.head, nex

    def mergeSorted(self, a, b):
        if a == None:
            return self.mergeSorted(*self.split(b))
        if b == None:
            return self.mergeSorted(*self.split(a))
        else:
            if(a.val <= b.val):
                a.next = self.mergeSorted(a.next, b)
                self.print_tail(a)
                return a
            else:
                b.next = self.mergeSorted(a, b.next)
                self.print_tail(b)
                return b
    
    def mergeSort(self):
        a, b = self.split(self.head)
        # print(a.val, b.val)
        self.head = self.mergeSorted(a, b)



if __name__ == "__main__":
    l = '15 20 2 3 5 10'
    l = reversed(l.split(' '))
    L = LinkedList()
    for i in l:
        L.add(int(i))
    L.print()
    L.mergeSort()
    L.print()