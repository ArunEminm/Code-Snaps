def is_valid(x):
    s = []
    xx = 0
    while(xx < len(x)):
        if(x[xx] in ['{', '[', '(']):
            s.append(x[xx])
        else:
            s.pop()
        xx += 1
    if(len(s) == 0):
        return 'true'
    else:
        return 'false'


if __name__ == "__main__":
    x = input().rstrip()
    print(is_valid(x))