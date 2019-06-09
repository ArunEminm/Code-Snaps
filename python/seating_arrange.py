def find_opp(n):
    _mp = {
        0: 'WS',
        1: 'WS',
        2: 'MS',
        3: 'AS',
        4: 'AS',
        5: 'MS',
    }
    mod = n % 12
    if mod == 1:
        opp = n + 11
    elif mod == 2:
        opp = n + 9
    elif mod == 3:
        opp = n + 7
    elif mod == 4:
        opp = n + 5
    elif mod == 5:
        opp = n + 3
    elif mod == 6:
        opp = n + 1
    elif mod == 7:
        opp = n - 1
    elif mod == 8:
        opp = n - 3
    elif mod == 9:
        opp = n - 5
    elif mod == 10:
        opp = n - 7
    elif mod == 11:
        opp = n - 9
    else:
        opp = n - 11
    
    # print(opp % 6)
    return '%s %s' % (opp, _mp[(opp % 6)])


if __name__ == '__main__':
    test = int(input())
    for i in range(0, test):
        seat = int(input())
        print(find_opp(seat))