#include <iostream>
using namespace std;
template <class T>
class Sample
{
private:
    T n;

public:
    Sample(T a) : n(a)
    {
        cout << "Sample " << n << " is created." << endl;
    }
    Sample(const Sample &X)
    {
        n = X.n;
        cout << "Sample " << n << " is copied." << endl;
    }
    Sample &add(Sample s)
    {
        n += s.n;
        return *this;
    }
    void show()
    {
        cout << n << endl;
    }
};

// ================================AppendCode================================
int main()
{
    int a, b;
    double c, d;
    cin >> a >> b >> c >> d;
    Sample<int> s1(a), s2(b), s3(s1);
    Sample<double> s4(c), s5(d), s6(s5);
    s1.add(s2);
    s1.show();
    s5.add(s4);
    s5.show();
    return 0;
}