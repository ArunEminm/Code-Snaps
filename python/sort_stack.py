

steps = 0

class Stack:

    def __init__(self):
        self._s = []

    def push(self, val):
        self._s.append(val)
    
    def peek(self):
        s = self._s.pop()
        self.push(s)
        return s

    def pop(self):
        return self._s.pop()

    @property
    def isEmpty(self):
        return len(self._s) == 0
    
    def sort(self):
        global steps
        steps += 1
        if(not self.isEmpty):
            t = self.pop()
            self.sort()
            self.sortInsert(t)
    
    def sortInsert(self, t):
        global steps
        steps += 1
        if (self.isEmpty or (not self.isEmpty and t < self.peek())):
            self.push(t)
        else:
            te = self.pop()
            self.sortInsert(t)
            self.push(te)



if __name__ == "__main__":
    inputs = list(map(int, input().rstrip().split(' ')))
    s = Stack()
    for i in inputs:
        s.push(i)
    
    s.sort()
    print(s._s)
    
    print(steps)
