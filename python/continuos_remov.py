def remove(x):
    l = len(x)
    i = 0
    s = ''
    while(i < l):
        # print(i)
        if(i < l - 1):
            if(x[i + 1] > x[i]):
                j = i + 1
                # print(j, l)
                while(j < l and x[j] == x[i+1]):
                    j += 1
                if(j > i + 2):
                    s += x[i]
                    i = j
                else:
                    s += x[i]
                    i += 1
            else:
                s += x[i]
                i += 1
        else:
            s += x[i]
            i += 1
    return s

if __name__ == "__main__":
    x = input().rstrip()
    print(remove(x))