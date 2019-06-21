# Python3 program to count 
# Minimum number of adjacent 
# swaps so that the largest 
# element is at beginning and 
# the smallest element is at last. 
def minSwaps(arr): 
	'''Function that returns 
	the minimum swaps'''
	
	n = len(arr) 
	maxx, minn, l, r = -1, arr[0], 0, 0

	for i in range(n): 
		
		# Index of leftmost 
		# largest element 
		if arr[i] > maxx: 
			maxx = arr[i] 
			l = i 
			
		# Index of rightmost 
		# smallest element 
		if arr[i] <= minn: 
			minn = arr[i] 
			r = i 
			
	if r < l: 
		print(l + (n - r - 2)) 
	else: 
		print(l + (n - r - 1)) 
		
# Driver code 
arr = [5, 6, 1, 3] 

minSwaps(arr) 

# This code is contributed 
# by Tuhin Patra 
