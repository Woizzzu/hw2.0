#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    cout << "Программа анализа N чисел\n";
    cout << "Введите количество чисел (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: количество чисел должно быть больше 0!\n";
        return 1;
    }

    double currentNumber;
    double sum = 0.0;
    double maxVal;
    double minVal;

    cout << "Введите число 1: ";
    cin >> currentNumber;
    sum += currentNumber;
    maxVal = currentNumber;
    minVal = currentNumber;

    for (int i = 2; i <= n; i++) {
        cout << "Введите число " << i << ": ";
        cin >> currentNumber;

        sum += currentNumber;

        if (currentNumber > maxVal) {
            maxVal = currentNumber;
        }
        if (currentNumber < minVal) {
            minVal = currentNumber;
        }
    }

    double average = sum / n;

    cout << "\nРезультаты анализа\n";
    cout << "Сумма: " << sum << endl;
    cout << "Среднее значение: " << average << endl;
    cout << "Максимум: " << maxVal << endl;
    cout << "Минимум: " << minVal << endl;

    return 0;
}
