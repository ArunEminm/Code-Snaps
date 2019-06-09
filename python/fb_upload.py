def decision(l, h, w):
    if(l > h or l > w):
        return 'UPLOAD ANOTHER'
    elif(w == h and l <= h and l <= w):
        return 'ACCEPTED'
    else:
        return 'CROP IT'
        
if __name__ == "__main__":
    l = int(input())
    for i in range(int(input())):
        h, w = list(map(int, input().rstrip().split()))
        print(decision(l, h, w))