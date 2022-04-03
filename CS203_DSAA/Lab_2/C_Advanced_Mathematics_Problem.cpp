/*
Given F(x) = xex/20 - b, (x ϵ R, e is a constant approximately 
equal to 2.718281828459, also known as Euler number , b is a given integer).
Please find the zero point of F(x) .
*/
#include <iostream>
#include <math.h>
using namespace std;
const long double e = 2.718281828459;
int main()
{
    int T;
    long double b, x, x0 = 100.0;
    cin >> T;
    auto f = [](double x, double b) { return x * pow(e, x / 20.0) - b; };
    auto g = [](double x) { return (1.0 + x / 20.0) * pow(e, x / 20.0); };
    for (int i = 0; i < T; i++) {
        cin >> b;
        for (x = x0; (f(x, b) > 0 ? f(x, b) : -f(x, b)) >= 0.01; x = x - f(x, b) / g(x))
            ;
        printf("%.10Lf\n", x);
    }
    return 0;
}