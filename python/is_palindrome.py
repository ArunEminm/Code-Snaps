def is_palindrom(a):
    l = len(a)
    if(l % 2 == 1):
        return a[l // 2:] == a[:(l // 2 + 1)][::-1]
    else:
        return a[l // 2:] == a[:(l // 2)][::-1]


if __name__ == "__main__":
    a = input()
    if(is_palindrom(a)):
        print('YES')
    else:
        print('NO')