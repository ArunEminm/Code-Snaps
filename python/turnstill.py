def getTimes(time, direction):
    last_used = None
    t_pass = []
    delay = 0
    for i in range(0, len(time) - 1):
        if(direction[i + 1] == direction):
            if(direction[i + 1] == 0):
                t_pass.append(t[i] + delay)
                delay += 1
            else:
                



if __name__ == "__main__":
   time_count = int(input().strip())

    time = []

    for _ in range(time_count):
        time_item = int(input().strip())
        time.append(time_item)

    direction_count = int(input().strip())

    direction = []

    for _ in range(direction_count):
        direction_item = int(input().strip())
        direction.append(direction_item)

    result = getTimes(time, direction)