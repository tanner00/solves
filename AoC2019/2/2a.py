program = [int(v) for v in input().split(',')]
program_size = len(program)

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

print(program[0])
