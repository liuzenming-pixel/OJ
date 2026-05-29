#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Equation
{
private:
    double aa, bb, cc, x1, x2;

public:
    Equation(double a, double b, double c) : aa(a), bb(b), cc(c) {}

    void solve()
    {
        x1 = (-bb + sqrt(bb * bb - 4 * aa * cc)) / (2 * aa);
        x2 = (-bb - sqrt(bb * bb - 4 * aa * cc)) / (2 * aa);
    }
    void printRoot()
    {
        cout << fixed<< setprecision(2) << x1 << " " << x2 << endl;
    }
};

// ================================AppendCode================================
int main()
{
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        Equation equ(a, b, c);
        equ.solve();
        equ.printRoot();
    }
    return 0;
}