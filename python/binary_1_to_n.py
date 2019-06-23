def generate(n):
    q = []
    q.append('1')
    for i in range(1, n):
        x = q.pop(0)
        print(x)
        x1 = x + '0'
        q.append(x1)
        x2 = x + '1'
        q.append(x2)


if __name__ == "__main__":
    n = int(input())
    generate(n)