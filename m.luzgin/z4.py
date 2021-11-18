from random import randint


massiv = [randint(0, 100) for _ in range(randint(1, 11))]
print(massiv)
step = 0
print(len(massiv))
for i in range(len(massiv)+1):
    print(i)
    if (i + 1) == len(massiv):
        break
    max_value = massiv[i]
    next_value = massiv[i+1]
    while next_value <= max_value:
        next_value += 1
        step += 1
    massiv[i+1] = next_value
print(massiv)
print(step)



