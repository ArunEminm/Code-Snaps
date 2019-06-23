
class Node:

    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = None
        self.right = None

    
def minDepth(self):
    q = [] 
    if self == None:
        return 0
    q.append({'node': self, 'depth':1})
    c = self
    while(len(q) > 0):
        i = q.pop(0)
        node = i['node']
        depth = i['depth']
        if node.left is None and node.right is None:
            return depth
        
        if node.left is not None:
            q.append({'node': node.left, 'depth': depth + 1})
        if node.right is not None:
            q.append({'node': node.right, 'depth': depth + 1})
        

if __name__ == "__main__":
    root = Node(1) 
    root.left = Node(2) 
    root.right = Node(3) 
    root.left.left = Node(4) 
    root.left.right = Node(5) 
    print(minDepth(root))