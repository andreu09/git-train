#include <iostream>

using namespace std;

int main() {

    int n = 0; // Размерность матрицы
    int a = 1; // Значение нулевого элемент матрицы
    setlocale(LC_ALL, "Russian"); // Установка языка

    cout << "Задание 1\nВыполнил Шмаков А.Ю." << endl;
    cout << "Введите значение n = ";
    cin >> n;
    n = (2 * n) - 1;

    // Определение динамического массива, по заданию n - любое число, поэтому размерность матрицы не ограничена
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        *(arr + i) = new int[n];

    cout << "Размер матрицы: " << n << "x" << n << endl;;

    // Заполнение матрицы значениями от 1 до n^2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            arr[i][j] = a++;
    }

    cout << "Введенная матрица:" << endl;;

    // Вывод исходной матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "Результат:" << endl;

    int initI = (n / 2); // Значение строки элемента, с которого начинается итерация
    int initJ = (n / 2); // Значение столбца элемента, с которого начинается итерация
    int stepLB = 1; // Начальное кол-во шагов по матрице влево и вниз
    int stepRT = 2; // Начальное кол-во шагов по матрице вправо и вверх

    // Цикл прохода по всей матрице
    while (true) {

        // Цикл прохода по матрице влево
        for (int j = initJ, step = 0; step < stepLB;) {
            cout << arr[initI][j] << " ";
            step++;
            j--;
            initJ = j;
        }

        // Алгоритим заканчивается, если кол-во шагов влево стало равно размерности матрицы
        if (stepLB == n)
            break;

        // Цикл прохода по матрице вниз
        for (int i = initI, step = 0; step < stepLB;) {
            cout << arr[i][initJ] << " ";
            step++;
            i++;
            initI = i;
        }

        // Цикл прохода по матрице вправо
        for (int j = initJ, step = 0; step < stepRT;) {
            cout << arr[initI][j] << " ";
            step++;
            j++;
            initJ = j;
        }

        // Цикл прохода по матрице вверх
        for (int i = initI, step = 0; step < stepRT;) {
            cout << arr[i][initJ] << " ";
            step++;
            i--;
            initI = i;
        }

        // Увеличиваем кол-во шагов в стороны по матрице
        stepLB += 2;
        stepRT += 2;
    }

    delete[] arr; // Чистим память от массива
    cout << endl;
    system("pause");
    return 0;
}