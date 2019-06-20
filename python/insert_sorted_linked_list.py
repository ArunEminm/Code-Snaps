class Node:

    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next
    
    def __str__(self):
        return str(self.val)
    
    def print(self):
        print('%s-%s-%s' % (s.prev, self.val, self.next))


class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    def insertSorted(self, v):
        no = Node(v)
        if self.head == None:
            self.addNew(v)
        else:
            if(v < self.head.val):
                no.next = self.head
                self.head.prev = no
                self.head = no
            elif(v > self.tail.val):
                self.tail.next = no
                no.prev = self.tail
                self.tail = no
            else:
                c = self.head
                while(v > c.val):
                    c = c.next
                no.next = c
                no.prev = c.prev
                c.prev.next = no
                c.prev = no
            

    def addNew(self, val):
        no = Node(val)
        if self.head == None:
            self.head = no
            self.tail = self.head
            self.tail.prev = self.head
            self.head.next = self.tail
        else:
            self.tail.next = no
            no.prev = self.tail
            self.tail = no
        return no

    def print(self):
        c = []
        cc = self.head
        while(cc):
            c.append(cc.val)
            cc = cc.next

        print(c)
    
    def delete(self, node):
        if(node.prev):
            node.prev.next = node.next
        if(node.next):
            node.next.prev = node.prev
        


if __name__ == "__main__":
    t= int(input().rstrip())
    l = LinkedList()
    _l = []
    for i in range(t):
        _l.append(l.addNew(int(input().rstrip())))
    
    l.print()
    l.insertSorted(4)
    l.print()
    print(_l[2])
    l.delete(_l[2])
    l.print()
    l.delete(_l[3])
    l.print()