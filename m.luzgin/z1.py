from random import randint
n = int(input("n = "))


def construct_matrix(z):
    mat = [[randint(1, 100) for _ in range(2 * z - 1)] for _ in range(2 * z - 1)]
    return mat


matrix = construct_matrix(n)
answer = []
for i in matrix[0]:
    answer.append(i)
size = 2 * n - 1
index = size
r = size
y = 0
x = size - 1
while index < size ** 2:
    r -= 1
    for _ in range(r):  # вертикальное перемещение вниз
        y += 1
        index += 1
        answer.append(matrix[y][x])
    for _ in range(r):  # горизонтальное перемещение влево
        x -= 1
        index += 1
        answer.append(matrix[y][x])
    r -= 1
    for _ in range(r):  # вертикальное перемещение вверх
        y -= 1
        index += 1
        answer.append(matrix[y][x])
    for _ in range(r):  # горизонтальное перемещение вправо
        x += 1
        index += 1
        answer.append(matrix[y][x])
answer = list(reversed(answer))
answer = ' '.join(map(str, answer))
print(answer)







