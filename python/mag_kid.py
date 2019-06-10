def heapify(arr, n, i): 
    # print('22', arr, n, i)
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
    


if __name__ == "__main__":
    # A = list(map(int, input().rstrip().split()))
    A = [1, 2, 4, 8, 3, 5, 6]
    A = [ 2147483647, 2000000014, 2147483647 ]
    for i in range(len(A) - 1, -1, -1):
        heapify(A, len(A), i)
    # print(A)
    # k = int(input())
    k = 10
    s = 0
    for i in range(k):
        s += A[0]
        s %= 1000000007
        A[0] = A[0]//2
        heapify(A, len(A), 0)
        print(i, A)
    print(s)