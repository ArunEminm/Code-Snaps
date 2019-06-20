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
            node.next.prev = node.p
    
    def compare(self, l2):
        l1 = self.head
        l2 = l2.head
        while(l1 and l2 and l1.val == l2.val):
            l1 = l1.next
            l2 = l2.next
    
        if (l2 and not l1):
            return -1
        elif(l1 and not l2):
            return 1
        elif(not (l1 or l2)):
            return 0
        else:
            if l1.val > l2.val:
                return 1
            else:
                return -1

    

if __name__ == "__main__":
    l11 = 'geeksa'
    l12 = 'geeksb'
    l21 = 'geeksa'
    l22 = 'geeks'
    l31 = 'geeks'
    l32 = 'geeks'


    l1 = LinkedList()
    for i in l11:
        l1.addNew(i)
    l2 = LinkedList()
    for i in l12:
        l2.addNew(i)
    
    print(l1.compare(l2))

    l1 = LinkedList()
    for i in l21:
        l1.addNew(i)
    l2 = LinkedList()
    for i in l22:
        l2.addNew(i)
    
    print(l1.compare(l2))

    l1 = LinkedList()
    for i in l31:
        l1.addNew(i)
    l2 = LinkedList()
    for i in l32:
        l2.addNew(i)
    
    print(l1.compare(l2))