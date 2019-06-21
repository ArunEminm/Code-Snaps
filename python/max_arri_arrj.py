def maxDifference(arr): 
	n = len(arr)
	max__ = -1
	maxRight = arr[n - 1] 

	for i in range(n - 2, -1, -1): 
		if (arr[i] > maxRight): 
			maxRight = arr[i] 
		else: 
			diff = maxRight - arr[i] 
			if (diff > max__): 
				max__ = diff 
	return max__ 


if(__name__ == '__main__'): 
    t = int(input())
    n = t
    arr = []
    while(t > 0):
        arr.append(int(input()))
        t -= 1
    max__ = maxDifference(arr, n) 
    print (max__) 
