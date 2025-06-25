import math

EPS = 10**(-9)

def solve(n):
    v = [0] * n

    avg = [0.0, 0.0]
    for i in range(n):
        inp = input().split()
        v[i] = [float(inp[0]), float(inp[1])]
        angle = float(inp[3])
        if(angle < 0):
            angle += 360

        for j in range(4, len(inp), 2):
            if(inp[j] == "walk"):

                d = float(inp[j + 1])
                radAngle = math.radians(angle)

                x = math.cos(radAngle) * d
                y = math.sin(radAngle) * d

                v[i][0] += x
                v[i][1] += y
            else:
                angle += float(inp[j + 1])
                if(angle < 0):
                    angle += 360
                if(angle >= 360):
                    angle -= 360
        avg[0] += v[i][0]
        avg[1] += v[i][1]

    avg[0] /= n
    avg[1] /= n
    bd = 0.0
    for i in v:
        x = avg[0] - i[0]
        y = avg[1] - i[1]
        d = x * x + y * y
        bd = max(bd, math.sqrt(d))

    print(f'{round(avg[0], 4)} {round(avg[1], 4)} {round(bd, 4)}')

n = 1
while n:
    n = int(input())
    if(n == 0):
       break
    solve(n)