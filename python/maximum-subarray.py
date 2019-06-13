import sys

class Solution:
    
    def maxSubArray(self, nums):
        max_ending_here = 0
        max_so = -sys.maxsize - 1
        
        for i in range(len(nums)):
            max_ending_here += nums[i]
            
            if(max_so < max_ending_here):
                max_so = max_ending_here

            if(max_ending_here < 0):
                max_ending_here = 0
        
        return max_so


if __name__ == "__main__":
    print(Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))