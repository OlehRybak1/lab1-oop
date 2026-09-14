// Лабораторна робота №1, Завдання 1 (варіант 4)
// Обчислення значень функцій a[x,y,z,b] і b[x,y,z]

#include <iostream>
#include <iomanip>
#include "ZavdClass.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(6);
    cout << "=== Лабораторна робота №1. Завдання 1 (варіант 4) ===\n\n";

    char again = 'y';
    while (again == 'y' || again == 'Y')
    {
        double x, y, z;

        cout << "Введіть x: ";
        cin >> x;
        cout << "Введіть y: ";
        cin >> y;
        cout << "Введіть z: ";
        cin >> z;

        ZavdClass Zavd;
        Zavd.Fn_b(x, y, z); // спочатку обчислюємо b, оскільки a залежить від b
        Zavd.Fn_a(x, y, z);

        cout << "\nРезультати для x=" << x << ", y=" << y << ", z=" << z << ":\n";
        cout << "b[x,y,z]   = " << Zavd.getb() << '\n';
        cout << "a[x,y,z,b] = " << Zavd.geta() << '\n';

        cout << "\nОбчислити ще раз для нових даних? (y/n): ";
        cin >> again;
        cout << '\n';
    }

    return 0;
}
