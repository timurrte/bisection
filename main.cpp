#include <iostream>
using namespace std;

/*double f(double x) {
    return pow(x, 3) - 3 * pow(x, 2) + 6 * x - 2;
}*/

double f(double x) {
    return (4 * x - x ^ 3 + 8);
}

double FindRoot(double (*f)(double), double a, double b, double eps) {
    double c;
    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;
        if ((f(a) * f(c)) > 0) a = c;
        else b = c;
    }
    return c;
}
int main() {
 
    double a, b, eps, x;
    a = 0;
    b = 3;
    eps = 0.0001;

    if (f(a) * f(b) > 0) {
        cout << "Wrong interval!\n";
        return 0;
    }

    x = FindRoot(f, a, b, eps);
    cout << "x = " << x << endl;
    return 0;
}