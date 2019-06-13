class Solution:

    def spiralOrder(self, matrix):
        x = [0, len(matrix) - 1]
        y = [0, len(matrix) - 1]
        xx = []
        di = ['right', 'down', 'left', 'up']
        di = 'right'
        while(x[0] < len(matrix) and y[0] < len(matrix)):
            if(di == 'right'):
                for i in range(y[0], y[1] + 1):
                    # print('right', i)
                    xx.append(matrix[x[0]][i])
                y[0] += 1
                di = 'down'
            elif(di == 'down'):
                for i in range(y[0], y[1] + 1):
                    # print('down', i)
                    xx.append(matrix[i][x[1]])
                x[1] -= 1
                di = 'left'
            elif(di == 'left'):
                for i in range(x[1], x[0] - 1, -1):
                    # print('left', i)
                    xx.append(matrix[y[1]][i])
                y[1] -= 1
                di = 'up'
            elif(di == 'up'):
                for i in range(y[1], y[0] - 1, -1):
                    # print('up', i, y)
                    xx.append(matrix[i][x[0]])
                x[0] += 1
                di = 'right'
            # print(x, y)
        return xx


if __name__ == "__main__":
    a = [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]
    print(Solution().spiralOrder(a))