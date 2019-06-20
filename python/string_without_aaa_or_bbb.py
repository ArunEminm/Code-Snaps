class Solution:
    
    def strWithout3a3b(self, A: int, B: int) -> str:
        output = ""
        a = 0  # length of last sequence of 'a'
        b = 0  # length of last sequence of 'b'
        
        size = A+B
        i = 0
        while(i < size):
            if(A > B and a < 2) or b == 2:
                output += 'a'
                A -= 1
                a += 1
                b = 0
            else:
                output += 'b'
                B -= 1
                b += 1 
                a = 0
            i += 1

        return output

if __name__ == "__main__":
    print(Solution().strWithout3a3b(10, 2))