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

    matches += 1 if has_two_adj and increases else 0

print(matches)
