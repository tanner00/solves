from itertools import groupby

START = 272091
END = 815432

matches = 0
for p in range(START, END):
    p = str(p)

    has_two_adj = False
    increases = True

    for i in range(0, len(p) - 1):
        if p[i] == p[i + 1]:
            has_two_adj = True
        if p[i] > p[i + 1]:
            increases = False

    big_group = True
    if has_two_adj and increases:
        for v in [(a, sum(1 for _ in b)) for a, b in groupby(p)]:
            if v[1] == 2:
                big_group = False
                break
            
    matches += 1 if has_two_adj and increases and not big_group else 0

print(matches)
