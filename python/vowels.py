import collections

def get_sum(t):
    _l = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    d = {}
    for index, i in enumerate(_l):
        d[i] = index
    ex = collections.defaultdict(list)
    li = list(t)
    l = len(t)
    # print(l)
    # print(d)
    for index, i in enumerate(li):
        # print(index, i)
        if(i in d):
            ex[i].append(index)
    
    rep = 0
    # print(ex)
    for k, v in ex.items():
        for vv in v:
            # print('1', i, k, vv)
            # _l_dist = vv + 1
            # _r_dist = l - vv
            # appear = min(_l_dist, _r_dist, l-i+1)
            # print('2', vv, _l_dist, _r_dist, i, appear)
            # print(k, vv)
            rep += (l - vv) * (vv + 1) 
    return rep


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        print(get_sum(input()))