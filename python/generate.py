import random


a = []
for i in range(0, 1000000):
    a.append(random.randint(0, 1000000))

print(' '.join(list(map(str, a))))
print(10000)
