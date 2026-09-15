#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


class FunctionCalculator {
private:
    double a, b;

public:
    FunctionCalculator() : a(1), b(1) {}   

    
    void Fn_b(double x, double y, double z) {
        double b1 = (x + y) / pow(fabs(z), 0.6) + pow(sin((x + z * z) / (2 * x + y)), 2);
        double b2 = z * exp((x * x - y) / (1 + z));
        b = pow(fabs(b1), 1.0 / 3.0) - b2;
    }

    
    void Fn_a(double x, double y, double z) {
        double a1 = z / (x * x) + pow(sin(b), 2);
        double a2 = fabs((x * x + y) / (z + pow(x, 3) / 3));
        double a3 = log(fabs(x * x + z));
        a = y * y + a1 / (a2 - a3);
    }

    double geta() const { return a; }
    double getb() const { return b; }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int variant;
    cout << "Enter variant number: ";
    cin >> variant;

    double x = 0.48 * variant;
    double y = 0.47 * variant;
    double z = -1.32 * variant;

    cout << fixed << setprecision(6);
    cout << "\n--- Task 1: single calculation ---\n";
    cout << "x = " << x << "   y = " << y << "   z = " << z << endl;

    FunctionCalculator calc;
    calc.Fn_b(x, y, z);
    calc.Fn_a(x, y, z);

    cout << "a[x,y,z,b] = " << calc.geta() << endl;
    cout << "b[x,y,z]   = " << calc.getb() << endl;

    double xn = -1.0;
    double xk = 1.0;
    double dx = 0.2;

    cout << "\n--- Task 2: tabulation of a and b over x in [-1, 1], step 0.2 ---\n";
    cout << "(y = " << y << ", z = " << z << " fixed)\n\n";
    cout << "         x |                a |                b\n";
    cout << "---------------------------------------------------\n";

    int steps = round((xk - xn) / dx);
    for (int i = 0; i <= steps; ++i) {
        double xi = xn + i * dx;

        if (fabs(xi) < 1e-9) {
            xi = 0.0;
        }

        FunctionCalculator tab;
        tab.Fn_b(xi, y, z);
        tab.Fn_a(xi, y, z);

        cout << setw(10) << xi << " | "
            << setw(16) << tab.geta() << " | "
            << setw(16) << tab.getb() << endl;
    }

    return 0;
}