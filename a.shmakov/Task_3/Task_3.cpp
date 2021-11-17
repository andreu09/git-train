#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка языка
    int sumL = 0, sumR = 0; // Сумма половины числа справа и слева
    vector<int> ticket; // Вектор значений цифр билета
    int input; // Вводимый номер билета

    cout << "Задание 3\nВыполнил Шмаков А.Ю." << endl;
    cout << "Введите номер билета: " << endl;

    cin >> input;

    while (input > 0)
    {
        ticket.push_back(input % 10);
        input /= 10;
    }

    // Проверка на четное кол-во цифр в билете
    if (!(ticket.size() % 2)) {
        sumL  = accumulate(ticket.begin() + (ticket.size()/2), ticket.end(), 0);
        sumR  = accumulate(ticket.begin(), ticket.end() - (ticket.size() / 2), 0);
        (sumL == sumR) ? (cout << "true") : (cout << "false");
    }
    else {
        cout << "Номер билета должен содержать четное кол-во знаков!" ;
    }  
    cout << endl;
    system("pause");
    return 0;
} 