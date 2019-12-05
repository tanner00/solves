def get_points():
    line = input().split(',')
    points = []
    curx, cury = 0, 0
    for d in line:
        should_move = int(d[1:])
        if d[0] == 'U':
            while should_move != 0:
                cury -= 1
                points.append((curx, cury))
                should_move -= 1
        elif d[0] == 'D':
            while should_move != 0:
                cury += 1
                points.append((curx, cury))
                should_move -= 1
        elif d[0] == 'L':
            while should_move != 0:
                curx -= 1
                points.append((curx, cury))
                should_move -= 1
        elif d[0] == 'R':
            while should_move != 0:
                curx += 1
                points.append((curx, cury))
                should_move -= 1
        

    return set(points)

p1 = get_points()
p2 = get_points()

mind = 99999999999999999
for p in (p1 & p2):
    mind = min(mind, abs(p[0]) + abs(p[1]))

print(mind)
