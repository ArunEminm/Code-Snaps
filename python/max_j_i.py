def maxDifference(arr, n): 
    max__ = 0; 
    __l = [0] * n 
    __r = [0] * n 
  
    __l[0] = arr[0] 
    for i in range(1, n): 
        __l[i] = min(arr[i], __l[i - 1]) 
  
    __r[n - 1] = arr[n - 1] 
    for j in range(n - 2, -1, -1): 
        __r[j] = max(arr[j], __r[j + 1]); 

    
    print(arr)
    print(__l)
    print(__r)
  
    i, j = 0, 0
    max__ = -1
    while (j < n): 
        if (__l[i] < __r[j]): 
            max__ = max(max__, arr[j] - arr[i]) 
            j = j + 1
            
    return max__ 


# Driver Code 
if(__name__ == '__main__'): 
    t = int(input())
    n = t
    arr = []
    while(t > 0):
        arr.append(int(input()))
        t -= 1
    max__ = maxDifference(arr, n) 
    print (max__) 
  
# This code is contributed  
# by gautam karakoti 
