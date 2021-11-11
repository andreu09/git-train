raw_text = input("Введите строку для проверки, является ли она палиндромом: ")
text = raw_text.replace(" ", "")
if text == text[::-1]:
    print(True)
else:
    print(False)
