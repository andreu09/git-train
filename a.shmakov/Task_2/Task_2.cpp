#include <iostream>

using namespace std;

int main()
{
    string str = ""; // Вводимая строка
    string flag = "true"; // Флаг результата
    setlocale(LC_ALL, "Russian"); // Установка языка

    cout << "Задание 2\nВыполнил Шмаков А.Ю." << endl;
    cout << "Введите строку: ";
    cin >> str;

    int lenStr = str.length(); // Длина строки

    // Сравниваем пары крайних элементов стремясь к середине 
    for (int i = 0; i < (lenStr / 2); i++) {
        if (str[i] != str[lenStr - i - 1])
            flag = "false";
    }

    cout << "Результат: " <<  flag << endl;
    system("pause");
    return 0;
}
