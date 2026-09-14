#include "ZavdClass.h"
#include <cmath>

// Параметризований конструктор
ZavdClass::ZavdClass()
{
    a = 1;
    b = 1;
}

// Деструктор
ZavdClass::~ZavdClass()
{
}

// Обчислення факторіалу (допоміжна функція, наявна згідно діаграми класів)
double ZavdClass::Faktr(int n) const
{
    double f = 1;
    if (n > 1)
        for (int i = 2; i <= n; i++)
            f *= i;
    return f;
}

// Обчислення функції b[x,y,z]:
// b = | (x+y)/|z|^0.6 + sin^2( (x+z^2)/(2x+y) ) |^(1/3) - z*e^((x^2-y)/(1+z))
void ZavdClass::Fn_b(double x, double y, double z)
{
    double term1 = (x + y) / pow(fabs(z), 0.6);
    double term2 = pow(sin((x + z * z) / (2 * x + y)), 2);
    double inner = fabs(term1 + term2);

    b = pow(inner, 1.0 / 3.0) - z * exp((x * x - y) / (1 + z));
}

// Обчислення функції a[x,y,z,b]:
// a = y^2 + (z/x^2 + sin^2(b)) / | (x^2+y)/(z + x^3/3) | - ln|x^2+z|
void ZavdClass::Fn_a(double x, double y, double z)
{
    double numerator   = z / (x * x) + pow(sin(b), 2);
    double denominator = fabs((x * x + y) / (z + pow(x, 3) / 3));

    a = y * y + numerator / denominator - log(fabs(x * x + z));
}
