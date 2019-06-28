import string
import math

lower = string.ascii_lowercase[:26]
upper = string.ascii_uppercase[:26]

def repr(x):
    
    if x >= 0 and x < 10:
        return x
    if x >=10 and x < 36:
        return lower[x - 10]
    if x >= 36 and x < 62:
        return upper[x - 36]
    if x == 62:
        return '_'
    if x == 63:
        return '-'


def shiftbase(num, base, last_pw=None):
    # print(num, base)
    if(num > 0):
        max_base = int(math.log(num, base))
    else:
        max_base = 0
    # print('mb', max_base)
    s = ''
    max_exp_val = math.pow(base, max_base)
    if(num > base):
        c = int(num // max_exp_val)
    else:
        c = num
    # print('c', c)
    _repr = repr(c)
    num -= int(c * max_exp_val)
    t = ''
    if(last_pw == None):
        t = str(_repr)
    else:
        t = '0' * (last_pw - max_base - 1) + str(_repr)
    if(num >= 0 and max_base != 0):
        s = s + t + shiftbase(num, base, last_pw=max_base)
    else:
        s = s + t
    return s



if __name__ == '__main__':
    number, x = list([int(x) for x in input().rstrip().split()])
    print(shiftbase(number, x))