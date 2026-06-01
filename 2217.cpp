#include <iostream>
#include <iomanip>   // 用于 setprecision
#include <cmath>     // 用于 sqrt 开平方
using namespace std;

// 类模板 Complex
template <class T>
class Complex
{
private:
    T real, imag;  // 实部、虚部，类型由 T 决定
public:
    // 构造函数
    Complex(T r, T i) : real(r), imag(i) {}

    // 求模：√(real² + imag²)
    double getModulus()
    {
        return sqrt(real * real + imag * imag);
    }
};
// ================================AppendCode================================
int main()
{
    int a, b;
    double c, d;
    cin >> a >> b;
    Complex<int> c1(a, b);
    cout << setiosflags(ios::fixed) << setprecision(2) << c1.getModulus() << endl;
    cin >> c >> d;
    Complex<double> c2(c, d);
    cout << setiosflags(ios::fixed) << setprecision(2) << c2.getModulus() << endl;
    return 0;
}