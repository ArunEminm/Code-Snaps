def needle_in_haystack(hay, need):
    i = 0
    l = len(hay)
    n = len(need)
    if(hay == '' and need == ''):
        return 0
    if(hay == ''):
        return -1
    while(i < l):
        j = 0
        st = i
        # print('st', i)
        if(i + n - 1 < l):
            return -1
        while(i < l and j < n and hay[i] == need[j]):
            # print(hay[i], need[j])
            i += 1
            j += 1
        if(j == n):
            return st
        else:
            i = st + 1
    return -1

if __name__ == "__main__":
    hay, need = input().rstrip().rsplit(' ')
    # print(hay, need)
    print(needle_in_haystack(hay, need))