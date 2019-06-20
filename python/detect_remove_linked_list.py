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
        return no
    
    def add(self, v):
        self.add_in_front(v)
    
    def print(self):
        c = []
        cc = self.head
        while(cc):
            c.append(cc.val)
            print(cc.val)
            cc = cc.next

    def detect_and_remove(self):
        slow = self.head
        fast = self.head.next.next
        while(slow != fast):
            slow = slow.next
            fast = fast.next.next
        print('meet', slow.val)
        self.remove(slow)

    def remove(self, slow):
        p1 = slow
        p2 = slow
        print(p1.val, p2.val)
        k = 1
        p1 = p1.next
        while(p2 != p1):
            p1 = p1.next
            k += 1
        p2 = self.head
        for i in range(k):
            p2 = p2.next
        p1 = self.head
        prep2 = p2
        while(p2 != p1):
            prep2 = p2
            p2 = p2.next
            p1 = p1.next
        print('delete', p2.val)
        
        prep2.next = None
        

if __name__ == "__main__":
    l = LinkedList()

    _l = {}
    for i in range(1, 88):
        _l[i] = l.add_in_front(i)
    
    print(_l[1].next)
    _l[1].next = _l[42]
    print(_l[1].next.val)
    print(_l[44].next.val)
    l.detect_and_remove()
    l.print()


