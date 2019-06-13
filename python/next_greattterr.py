class Stack:

    def __init__(self):
        self._s = []

    def push(self, val):
        self._s.append(val)

    def pop(self):
        return self._s.pop()

    @property
    def isEmpty(self):
        return len(self._s) == 0

def next_greater(arr):
    s = Stack()
    s.push(arr[0])
     
    ss = []

    for i in range(1, len(arr)):
        
        ne = arr[i]
        while(not s.isEmpty):
            e = s.pop()
            if(e < ne):
                ss.append((e, ne))
            else:
                ss.append((e, -1))
                s.push(ne)
                break
    while(not s.isEmpty):
        ss.append((s.pop(), -1))

    return ss


if __name__ == "__main__":
    inputs = list(map(int, input().rstrip().split(' ')))
    print(inputs)
    print(next_greater(inputs))