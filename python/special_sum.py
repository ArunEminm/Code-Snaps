def special_sum(n):
    # sums = []
    # for i in range(0, len(n)):
    #     temp = []
    #     for j in range(0, len(n)):
    #         temp.append(sum(n[i:j+1]))
    #     sums.append(temp)
    
    # print(sums)
    sums = {}

    def _special(i):
        _s = 0
        index = i
        it = 0
        while(index + it < len(n)):
            # print(index, index + it)
            if((index, index+it+1) in sums):
                __s = sums[(index, index+it+1)]
            else:
                __s = sum(n[index:index+it+1])
                sums[(index, index+it+1)] = __s
            _s +=  __s
            it += 1
            index += it
        return _s
    max_ = 0
    for i in range(len(n)):
        _s = _special(i)
        if(_s > max_):
            max_ = _s
    return max_


if __name__ == "__main__":
    _ = input()
    arr = list(map(int, input().rstrip().split()))
    print(special_sum(arr))