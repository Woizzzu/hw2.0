#include <iostream>
#include <windows.h>

using namespace std;

// Функция для расчета возраста
void calculateAge() {
    int currentYear, birthYear;
    cout << "\nКалькулятор возраста\n";
    cout << "Введите текущий год: ";
    cin >> currentYear;
    cout << "Введите ваш год рождения: ";
    cin >> birthYear;
        if (birthYear > currentYear) {
        cout << "Ошибка: год рождения не может быть больше текущего года!\n";
    } else {
        int age = currentYear - birthYear;
        cout << "Ваш возраст: " << age << " лет.\n";
    }
}

// Функция для арифметических операций
void calculateArithmetic() {
    double num1, num2;
    char operation;
    cout << "\nАрифметический калькулятор\n";
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;
    cout << "Введите второе число: ";
    cin >> num2;

    switch (operation) {
        case '+':
            cout << "Результат: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Результат: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Результат: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Ошибка: деление на ноль невозможно!\n";
            } else {
                cout << "Результат: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Ошибка: неверный оператор!\n";
    }
}

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
        cout << "\nГЛАВНОЕ МЕНЮ\n";
        cout << "1. Расчитать возраст\n";
        cout << "2. Простые арифметические операции\n";
        cout << "3. Выход\n";
        cout << "Выберите пункт меню (1-3): ";
        cin >> choice;

        if (choice == 1) {
            calculateAge();
        } else if (choice == 2) {
            calculateArithmetic();
        } else if (choice != 3) {
            cout << "Неверный выбор \n";
        }
    } while (choice != 3);

    cout << "Программа завершена \n";
    return 0;
}