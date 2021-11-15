from random import randint

n = int(input("Enter the initial dimension of the matrix... "))
print()

dimension = 2*n-1
rotation = 0
counter = dimension**2

matrix = [[0]*dimension for i in range(dimension)]
final_list = []

matrix[dimension//2][dimension//2] = randint(0, 9)

for j in range(dimension//2):

    for i in range(dimension-rotation):
        matrix[j][i+j] = randint(0, 9)

        final_list.append(matrix[j][i+j])
        counter -= 1

    for i in range(j+1, dimension-j):
        matrix[i][-j-1] = randint(0, 9)

        final_list.append(matrix[i][-j-1])
        counter -= 1

    for i in range(j+1, dimension-j):
        matrix[-j-1][-i-1] = randint(0, 9)

        final_list.append(matrix[-j-1][-i-1])
        counter -= 1

    for i in range(j+1, dimension-(j+1)):
        matrix[-i-1][j] = randint(0, 9)

        final_list.append(matrix[-i-1][j])
        counter -= 1

    rotation += 2

# print(matrix)
# print()

final_list.append(matrix[dimension//2][dimension//2])
final_list.reverse()

# print(final_list)
# print()

print(' '.join(map(str, final_list)))
print()

for i in matrix:

    for j in i:
        print(j, end=' ')

    print()
