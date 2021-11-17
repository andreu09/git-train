﻿#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка языка
    cout << "Дополнительное задание\nВыполнил Шмаков А.Ю." << endl;

    int n; // Размер массива
    int action; // Действие
    int k = 0; // Кол-во ходов
    int z = 0; // Новое значение для изменяемого элемента
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    cout << "1 - заполнение массива вручную\n2 - заполнение массива рандомными числами" << endl;
    cin >> action;

    int* arr = new int[n]; // Выделение памяти для массива

    switch (action)
    {
        case 1:
            cout << "Вводите элемента массива: " << endl;
            for (int i = 0; i < n; i++)
                cin >> arr[i];         

                break;
        case 2: 
            for (int i = 0; i < n; i++) 
                arr[i] = rand() % 21 - 10;

                break;
    }

    cout << "Ваш исходный массив: " << endl;

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    for (int i = 0; i < (n - 1); i++) {

        // Если текущий элемент больше предыдущего
        if (arr[i] > arr[i+1]) {
            // Накапливаем шаг, он равен разнице следующего элемена и предыдущего минус 1 по модулю
            k += abs(arr[i + 1] - arr[i] - 1);
            z = abs(arr[i + 1] - arr[i] - 1);
            // Прибавляем к изменяемому элементу посчитанную разницу
            arr[i + 1] = arr[i + 1] + z; 
        }

        // Частный случай если предыдущий элемент раверн следующему
        // Все так же как и выше, только + 1
        if (arr[i] == arr[i + 1]) {
            k += 1;
            z = 1;
            arr[i + 1] = arr[i + 1] + z;
        }
    }

    cout << endl << "Ваша новая возрастающая последовательность: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl << "Минимальное кол-во шагов:" << k << endl;

    delete[] arr; // Очищаем память от массива
    system("pause");
    return 0;
}