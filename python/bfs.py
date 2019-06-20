from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)
    
    def addEdge(self, u, v):
        self.graph[u].append(v)

    def bfs(self, s):
        visited = {}
        order = []
        q = []
        q.append(s)
        visited[s] = True
        while(q):
            c = q.pop(0)
            order.append(c)
            for j in self.graph[c]:
                print(j)
                if j not in visited:
                    q.append(j)
                    visited[j] = True
        print(order)
            
    def dfs(self, b):
        visited = {}
        order = []
        s = []
        s.append(b)
        while(s):
            c = s.pop()
            if c not in visited:
                order.append(c)
                visited[c] = True

            for j in self.graph[c]:
                if j not in visited:
                    s.append(j)
        print(order)


if __name__ == "__main__":
    gr = Graph()
    t = int(input().rstrip())
    for i in range(t):
        gr.addEdge(*input().rstrip().rsplit())
    
    print(gr.graph)
    print(gr.bfs('2'))
    print(gr.dfs('0'))