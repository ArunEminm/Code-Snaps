import string

def l_rotate(arr, r):
    rot = r % len(arr)
    return arr[rot:] + arr[:rot]

def cipher(s, r):
    arr = list(string.ascii_lowercase[:26])
    l_arr = l_rotate(arr, r)
    num = list(range(10))
    l_num = l_rotate(num, r)
    ns = []
    for i in s:
        if(i.isupper()):
            i = arr.index(i.lower())
            ns.append(l_arr[i].upper())
        elif(i.isdigit()):
            i = num.index(int(i))
            ns.append(str(l_num[i]))
        elif(i.islower()):
            i = arr.index(i.lower())
            ns.append(l_arr[i])
        else:
            ns.append(i)


    return ''.join(ns)


if __name__ == "__main__":
    s = input()
    r = int(input())
    print(cipher(s, r))