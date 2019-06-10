import collections

def find_min_flips(i):
    d = collections.defaultdict(int)
    st = i[0]
    if(st == '0'):
        d['0b'] = 1
        pin = '0b'
    else:
        d['1b'] = 1
        pin = '1b'
        
    for j in range(1, len(i)):
        if(i[j] == st):
            d[pin] += 1
        else:
            if(i[j] == '1'):
                d['1a'] += 1
            else:
                d['0a'] += 1
    print(d)
    if(st == '0'):
        flips = d['0a']
    else:
        flips = d['1a']
    return flips                              


if __name__ == '__main__':
    t = int(raw_input().rstrip())
    for i in range(0, t):
        print(find_min_flips(raw_input().rstrip()))
        