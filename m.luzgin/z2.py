stroka = str(input("Ввод строки: "))


def is_polindrom(k):
    if len(k) == 1:
        return True
    for i in range(0, int(len(k)/2)):
        if k[i] != k[len(k)-i-1]:
            return False
    return True

print(is_polindrom(stroka))