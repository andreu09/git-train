numbers = str(input("Ввод номера (четное кол-во знаков): "))
if len(numbers) % 2 != 0:
    print("Нечетное кол-во знаков")


def is_lucky(k):
    sum1 = 0
    sum2 = 0
    r = int(len(numbers) / 2)
    i1 = k[:r]
    i2 = k[r:]
    for i in i1:
        sum1 += int(i)
    for j in i2:
        sum2 += int(j)
    if sum1 == sum2:
        return True
    else:
        return False


print(is_lucky(numbers))
