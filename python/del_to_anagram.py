import collections

def del_required(a, b):
    hasa = collections.defaultdict(int)
    for j in a:
        hasa[j] += 1
    hasb = collections.defaultdict(int)
    for j in b:
        hasb[j] += 1

    total = set(list(hasa.keys()) + list(hasb.keys()))
    diff = 0
    for i in total:
        if i in hasa and i in hasb:
            diff += abs(hasb[i] - hasa[i])
        elif i in hasa:
            diff += abs(hasa[i])
        else:
            diff += abs(hasb[i])
    
    return diff



if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        a, b = input(), input()
        print(del_required(a, b))