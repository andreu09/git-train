numbers = input("Введите номер билета, чтобы проверить счастливый ли он: ")
part1 = 0
part2 = 0

if numbers.isdigit():
    if len(numbers)%2 == 0:    
        for i in numbers[:len(numbers)//2]:
            part1 += int(i)
        for i in numbers[len(numbers)//2:]:
            part2 += int(i)

        if part1 == part2:
            print("Счастливый!")
        else:
            print("Не счастливый")
    else:
        print("Ошибка) Вы ввели нечетное число")
else:
    print("Ошибка. Вы ввели буквы, вместо цифр")