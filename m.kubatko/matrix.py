num = int(input("Введите число: "))
number = 2*num-1
matrix = []
row = []
# наполение матрицы числами от 1 до n
for k in range(1, number*number+1):        
    row.append(k)
    if len(row)==number:
        matrix.append(row)
        row = []
        continue

if len(matrix)==1:
    print(matrix[0][0])
else:
    spiral = []
    mid = number//2
    i = j = mid

    move = [{'i': 0, 'j': -1},
            {'i': 1, 'j': 0},
            {'i': 0, 'j': 1},
            {'i': -1, 'j': 0},]

    count = 0
    len_step  = 1

    spiral.append(matrix[i][j])

    f = True

    while f:
        move_indx = count % 4
        mi = move[move_indx]['i']
        mj = move[move_indx]['j']
        n = 0
        if n < len_step:
            for _ in range(n, len_step):        
                i += mi
                j += mj
                spiral.append(matrix[i][j])            
                if i == 0 and j == 0:
                    f = False        
                    break
        len_step = len_step+(count%2)
        count+=1

    for item in spiral:
        print(item, end=" ")
