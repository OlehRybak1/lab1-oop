#pragma once

// Клас ZavdClass реалізує обчислення функцій a[x,y,z,b] і b[x,y,z]
// згідно з індивідуальним завданням №4.
class ZavdClass
{
private:
    double a; // результат обчислення функції a
    double b; // результат обчислення функції b

public:
    ZavdClass();          // параметризований конструктор (a=1, b=1)
    ~ZavdClass();         // деструктор

    void Fn_b(double x, double y, double z);           // обчислення функції b[x,y,z]
    void Fn_a(double x, double y, double z);            // обчислення функції a[x,y,z,b]
    double Faktr(int n) const;                          // обчислення факторіалу (допоміжна функція)

    double geta() const { return a; }
    double getb() const { return b; }
};
