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

def find_count(l, r, k):
    c = 0
    # prime = is_prime(k)
    # return 0
    for i in range(l, r + 1):
        if(i % k == 0):
            c += 1
    return c



if __name__ == "__main__":
    arr = list(map(int, input().rstrip().split()))
    print(find_count(arr[0], arr[1], arr[2]))