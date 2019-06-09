class Solution:
    # @param A : tuple of integers
    # @param B : tuple of integers
    # @return a double
    def findMedianSortedArrays(self, A, B):
        lenA = len(A)
        lenB = len(B)
        i = 0
        j = 0
        newA = []
        while(i < lenA and j < lenB):
            if(A[i]<=B[j]):
                newA.append(A[i])
                i += 1
            else:
                newA.append(B[j])
                j += 1
        if(i < lenA):
            newA += A[i:]
        elif(j < lenB):
            newA += B[j:]

        l = len(newA) % 2
        if(l == 0):
            return (newA[len(newA)/2] + newA[len(newA) / 2 - 1]) / 2.0
        else:
            return newA[len(newA)/2]
        
        return newA
                


if __name__ == "__main__":
    print(Solution().findMedianSortedArrays(
        (0, 23),
        ()
    ))