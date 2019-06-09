import math


def is_prime(n):
    for i in range(2, n):
        sq = int(math.sqrt(i))
        for j in range(2, sq + 1):
            if(i % j == 0):
                # print(i, j)
                return False
            elif(j == sq):
                _li.append(i)
                return True


def  get_primes(n):
    _li = []
    if(n > 3):
        _li.append(2)
        _li.append(3)
    if(n == 2):
        _li.append(2)
    for i in range(2, n):
        sq = int(math.sqrt(i))
        for j in range(2, sq + 1):
            if(i % j == 0):
                # print(i, j)
                break
            elif(j == sq):
                _li.append(i)
            # print(j)
    return _li
    
if __name__ == '__main__':
    n = int(input())
    print(' '.join(map(str, get_primes(n))))
        
