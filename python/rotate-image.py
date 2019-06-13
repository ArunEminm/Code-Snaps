class Solution:
    def rotate(self, mat):
        N = len(mat)
        xx = N // 2
        for x in range(0, xx): 
            
            # Consider elements in group    
            # of 4 in current square 
            for y in range(x, N-x-1): 


                # temp = mat[x][y] 
    
                # # move values from right to top 
                # mat[x][y] = mat[y][N-1-x] 
    
                # # move values from bottom to right 
                # mat[y][N-1-x] = mat[N-1-x][N-1-y] 
    
                # # move values from left to bottom 
                # mat[N-1-x][N-1-y] = mat[N-1-y][x] 
    
                # # assign temp to left 
                # mat[N-1-y][x] = temp 

                # print('xy', x, y)
                
                t = mat[x][y]
                mat[x][y] = mat[y][N - 1 - x]
                mat[y][N-1-x] = mat[N-1-x][N-1-y] 
                mat[N-1-x][N-1-y] = mat[N-1-y][x] 
                mat[N-1-y][x]= t
            
                
            # for i in mat:
                # print(i)
            # print('----')
        return mat

if __name__ == "__main__":
    a = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]
    for i in a:
        print(i)
    for i in Solution().rotate(a):
        print(i)