def get_points():
    line = input().split(',')
    curx, cury = 0, 0
    moved = 0
    points = []
    distances = []
    for d in line:
        should_move = int(d[1:])
        if d[0] == 'U':
            while should_move != 0:
                moved += 1
                cury -= 1
                points.append((curx, cury))
                distances.append(moved)
                should_move -= 1
        elif d[0] == 'D':
            while should_move != 0:
                moved += 1
                cury += 1
                points.append((curx, cury))
                distances.append(moved)
                should_move -= 1
        elif d[0] == 'L':
            while should_move != 0:
                moved += 1
                curx -= 1
                points.append((curx, cury))
                distances.append(moved)
                should_move -= 1
        elif d[0] == 'R':
            while should_move != 0:
                moved += 1
                curx += 1
                points.append((curx, cury))
                distances.append(moved)
                should_move -= 1
    return points, distances

p1, d1 = get_points()
p2, d2 = get_points()

sum_distances = []
for i in set(p1) & set(p2):
    int_p1 = [j for j, v in enumerate(p1) if v == i]
    int_p2 = [j for j, v in enumerate(p2) if v == i]

    for j in int_p1:
        for k in int_p2:
            sum_distances.append(abs(d1[j]) + abs(d2[k]))

print(min(sum_distances))
