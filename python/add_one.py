class Solution:
    # @param A : list of integers
    # @return a list of integers
    def plusOne(self, A):
        a = list(reversed(A))
        if(a[0] + 1 == 10):
            carry = 1
            a[0] = 0
            if(len(a) == 1):
                a.append(1)
                return ''.join(list(reversed(list(map(str, a)))))
        else:
            carry = 0
            a[0] = a[0] + 1
        for i in range(1, len(a)):
            while(carry != 0):
                a[i] += 1
                if(a[i] == 10):
                    a[i] = 0
                    carry = 1 
                elif(i == a[len(a) - 1] and carry == 1):
                    a.append('1')
                    carry = 0
                    break
                else:
                    carry = 0
                    break
        return ''.join(list(reversed(list(map(str, a)))))


if __name__ == "__main__":
    s = list(map(int, input().rstrip().split(' ')))
    print(Solution().plusOne(s))