class QueueNode:

    def __init__(self, val):
        self.val = val
        self.next = None
        # self.prev = None


class Queue:
    
    def __init__(self):
        self.front = None
        self.tail = None


    def enqueue(self, val):
        if(not self.tail):
            self.tail = QueueNode(val)
            self.front = self.tail
        else:
            tail = QueueNode(val)
            # tail.prev = self.tail
            self.tail.next = tail
            self.front = self.front or self.tail
            self.tail = tail
        return self
        

    def dequeue(self):
        if(self.front):
            val = self.front.val
            self.front = self.front.next
            return val
        else:
            return None


if __name__ == "__main__":
    s = int(raw_input())
    l = list(raw_input().rstrip().split())
    q = Queue()
    for i in range(0, len(l)):
        q.enqueue(l[i])
    query = int(raw_input())
    if(query == 1):
        val = raw_input()
        q.enqueue(val)
    if(query == 0):
        q.dequeue()
    
    c = q.front
    qq = []
    while(c):
        x = q.dequeue()
        if(x is not None):
            qq.append(x)
        c = q.front
    print(' '.join(qq))