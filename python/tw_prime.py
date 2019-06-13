import math

def get_primes(n):
    # n >= 3

    prime = {}
    steps = 0
    prime[2] = True
    prime[3] = True

    def _prime(e):
        sq = math.sqrt(e)
        if(e in prime):
            return prime[e]

        for j in range(2, int(sq) + 1):
            if(e % j == 0):
                return False
        print('prime', e)
        return True
    

    for i in range(2, n + 1):
        if(_prime(i)):
            prime[i] = True
            j = 2
            mul = i * j
            while(mul <= n):
                print(i, mul)
                prime[mul] = False
                j += 1 
                mul = j * i
                steps += 1

    print(prime)
    # print(steps)
    
    for i in range(2, n-2+1):
        if(prime[i] and prime[n-i]):
            return i, n-i
    

if __name__ == "__main__":
    n = int(input().rstrip())
    print(get_primes(n))