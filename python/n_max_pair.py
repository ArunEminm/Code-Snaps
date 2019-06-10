import math

def heapify(arr, n, i): 
    print('22', arr, n, i)
    largest = i # Initialize largest as root 
    l = 2 * i + 1	 # left = 2*i + 1 
    r = 2 * i + 2	 # right = 2*i + 2 

    # See if left child of root exists and is 
    # greater than root 
    if l < n and arr[i] < arr[l]: 
            largest = l 

    # See if right child of root exists and is 
    # greater than root 
    if r < n and arr[largest] < arr[r]: 
            largest = r 

    # Change root, if needed 
    if largest != i: 
            arr[i],arr[largest] = arr[largest],arr[i] # swap 

            # Heapify the root. 
            heapify(arr, n, largest) 



def getKth(A, k):
    if(k == 0):
        return A[0]
    B = sorted(A[int(math.log(k, 2)) + 1:2*(int(math.log(k, 2) + 1)) + 1], reverse=True)
    return B[0]


if __name__ == "__main__":
    A = [1, 4, 2, 3]
    B = [2, 5, 1, 6]
    for i in range(0, len(A)):
        heapify(A, len(A), i)
    for i in range(0, len(B)):
        heapify(B, len(B), i)
    
    d = {}
    
    maxA = [A[0]]
    maxB = [B[0]]
    if(len(A) == 1):
        print(maxA + maxB)
    sums = []
    a = []
    for i in range(0, len(A)//2):
        a.append(getKth(A, i))
        for j in range(len(A)//2):
            sums.append(getKth(B, j) + a[i])
    
    print(sorted(sums)[::-1][:len(A) + 1])