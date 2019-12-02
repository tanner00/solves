# URL: https://adventofcode.com/2019/day/2
# TYPE: Ad-Hoc

import sys

original = [int(v) for v in input().split(',')]

def try_program(noun, verb):
    # Copy the original
    program = list(original)
    program_size = len(program)

    program[1] = noun
    program[2] = verb
    
    for i in range(program_size // 4):
        op = program[i * 4 + 0]
        r1 = program[i * 4 + 1]
        r2 = program[i * 4 + 2]
        wo = program[i * 4 + 3]

        if op == 1:
            program[wo] = program[r1] + program[r2]
        elif op == 2:
            program[wo] = program[r1] * program[r2]
        elif op == 99:
            break
        else:
            print("Unknown opcode: {}".format(op))

    if program[0] == 19690720:
        print(100 * program[1] + program[2])
        sys.exit(0)

# Brute force the answer
# Problem says the value is [0, 99]
# O(n^2) is plenty good enough
for i in range(100):
    for j in range(100):
        try_program(i, j)
