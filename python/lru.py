class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.d = {}
        self.li = []
        self.cap = capacity
        self.add = {}

    # @return an integer
    def get(self, key):
        if(key in self.d):
            self.li = [self.add[key]] + self.li[:self.add[key]] + self.li[self.add[key] + 1:]
            self.add[key] = 0
            return self.d[key]
        return -1
        

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        self.d[key] = value
        if(len(self.li) == self.cap):
            self.li = self.li[:self.cap]

        if(key in self.add):
            self.li = self.li[:self.add[key]] + self.li[self.add[key] + 1:]
        self.li.insert(0, key)
        self.add[key] = 0
    
if __name__ == "__main__":
    a = LRUCache(10)
    a.set(4, 10)
    print(a.d)
    print(a.cap)
    print(a.li)
    print(a.add)

    a.set(5, 11)
    print(a.d)
    print(a.cap)
    print(a.li)
    print(a.add)

    a.set(5, 11)
    print(a.d)
    print(a.cap)
    print(a.li)
    print(a.add)

    a.get(5)

    print(a.d)
    print(a.cap)
    print(a.li)
    print(a.add)