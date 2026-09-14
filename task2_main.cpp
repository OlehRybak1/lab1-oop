// Лабораторна робота №1, Завдання 2 (варіант 4)
// Одновимірне табулювання функцій a[x,y,z,b] і b[x,y,z] за змінною x
// xп = -1, xк = 1, крок dx = 0.2 ("MultiLine" тут замінено виводом у консоль/файл)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "ZavdClass.h"

using namespace std;

int main()
{
    // Фіксовані значення y та z (беруться, як і в завданні 1, з даних варіанту)
    double y, z;
    cout << "=== Лабораторна робота №1. Завдання 2 (варіант 4) ===\n\n";
    cout << "Введіть фіксоване значення y: ";
    cin >> y;
    cout << "Введіть фіксоване значення z: ";
    cin >> z;

    const double xn = -1.0;   // xп
    const double xk = 1.0;    // xк
    const double dx = 0.2;    // крок

    cout << fixed << setprecision(6);
    cout << "\n" << setw(10) << "x" << setw(16) << "a[x,y,z,b]" << setw(16) << "b[x,y,z]" << "\n";
    cout << string(42, '-') << "\n";

    // Одночасно виводимо результат у текстовий файл table.txt (аналог MultiLine)
    ofstream fout("table.txt");
    fout << fixed << setprecision(6);
    fout << setw(10) << "x" << setw(16) << "a[x,y,z,b]" << setw(16) << "b[x,y,z]" << "\n";
    fout << string(42, '-') << "\n";

    for (double x = xn; x <= xk + 1e-9; x += dx)
    {
        // Функція a[x,y,z,b] містить ділення на x^2, тому в точці x=0 вона не визначена
        if (fabs(x) < 1e-9)
        {
            cout << setw(10) << x << setw(16) << "не визнач." << setw(16) << "-" << "\n";
            fout  << setw(10) << x << setw(16) << "не визнач." << setw(16) << "-" << "\n";
            continue;
        }

        ZavdClass Zavd;
        Zavd.Fn_b(x, y, z);
        Zavd.Fn_a(x, y, z);

        cout << setw(10) << x << setw(16) << Zavd.geta() << setw(16) << Zavd.getb() << "\n";
        fout  << setw(10) << x << setw(16) << Zavd.geta() << setw(16) << Zavd.getb() << "\n";
    }

    fout.close();
    cout << "\nРезультати також збережено у файл table.txt\n";

    return 0;
}
